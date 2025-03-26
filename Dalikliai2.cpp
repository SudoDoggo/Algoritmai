#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    vector<int> dal;
    vector<int> dalFull;
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		dal.push_back(temp);
	}
	sort(dal.begin(), dal.end());
	temp = dal[0] * dal[dal.size()-1];
	for (int i = 0; i < dal.size(); i++)
	{
		if (dal[i] * dal[dal.size() - 1 - i] != temp)
		{
			cout << -1;
			return 0;
		}
	}
	for (long long i = 2; i <= sqrt(temp); i++)
	{
		if (temp % i == 0)
		{
			if (i != temp / i)
				dalFull.push_back(temp / i);
			dalFull.push_back(i);
		}
	}
	if (dalFull.size() == dal.size())
		cout << temp;
	else
		cout << -1;
	return 0;
}
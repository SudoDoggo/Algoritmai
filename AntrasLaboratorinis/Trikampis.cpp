#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long BinarySearch(long long check)
{
	vector<long long> goodOnes;
	double S = 0;
	double p = 0;
	long long left = 0;
	long long middle = 0;
	long long right = check;
	if(check==1)
	{
	    return 2;
	}
	while (left <= right)
	{
		middle =(right + left) / 2;
		p = ((middle) + (middle+1)+(middle+2)) / 2.0 ;
		S = sqrt(p * (p - (middle)) * (p - (middle+1)) * (p - (middle+2)));
		if (S > check)
		{
			right = middle - 1;
			goodOnes.push_back(middle);
		}
		else if (S < check)
			left = middle + 1;
	}
	return left;
}
int main()
{
	int n = 0;
	cin >> n;
	long long ballAmount = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> ballAmount;
		long long mid = BinarySearch(ballAmount);
		cout << mid << " " << mid+1<<" " << mid + 2 << endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long BinarySearch(long long check)
{
	long long left = 0;
	long long right = check;
	long long middle = 0;
	unsigned long long middleSize = 0;
	vector<long long> goodOnes;
	while (left <= right)
	{
		middle =(right + left) / 2;
		middleSize = (1. / 6) * middle * (1 + middle) * (2 + middle);
		if (middleSize == check)
			return middle;
		else if (middleSize > check)
			right = middle - 1;
		else if (middleSize < check)
		{
			left = middle + 1;
			goodOnes.push_back(middle);
		}
	}
	sort(goodOnes.begin(), goodOnes.end());
	return goodOnes[goodOnes.size() - 1];
	return 0;
}
int main()
{
	int n = 0;
	cin >> n;
	long long ballAmount = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> ballAmount;
		cout << BinarySearch(ballAmount) << endl;
	}
	return 0;
}
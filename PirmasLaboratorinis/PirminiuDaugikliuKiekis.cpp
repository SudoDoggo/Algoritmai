#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int firstNr = 0;
	int secondNr = 0;
	cin >> firstNr>>secondNr;
	vector<int> arr(secondNr+1, 0);
	int maxK = 0;
	int max = 0;
	arr[1] = 1;
	for (int i = 1; i <= secondNr; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i; j <= secondNr; j += i)
			{
				if (j > arr.size())
					break;
				if(arr[j]==0)
					arr[j] = i;
			}
		}
	}
	int j = 0;
	int k = 0;
	for (int i = firstNr; i <= secondNr; i++)
	{
		if (i == 0)
			continue;
		j = i;
		k = 0;
		while (j != 1)
		{
			k++;
			j /= arr[j];
		}
		if (k >= maxK)
		{
			maxK = k;
			max = i;
		}
	}
	cout << max << endl;;
	return 0;
}
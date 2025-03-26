#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void DidBD(unsigned long long firstNr, unsigned long long secondNr, unsigned  long long& DBD)
{
	while (firstNr != 0 && secondNr != 0)
	{
		if (firstNr > secondNr)
			firstNr %= secondNr;
		else
			secondNr %= firstNr;
	}
	if (firstNr == 0)
		DBD = secondNr;
	else
		DBD = firstNr;
}
int main()
{
	unsigned long long firstNr = 0;
	unsigned long long secondNr = 0;
	unsigned long long DBD = 0;
	vector<unsigned long long> dal;
	cin >> firstNr>> secondNr;
	for (long long i = 1; i <= sqrt(firstNr); i++)
	{
		if (firstNr % i == 0)
		{
			if (i != firstNr / i)
				dal.push_back(firstNr / i);
			dal.push_back(i);
		}
	}
	sort(dal.begin(), dal.end());
	for (auto i : dal)
	{
		DidBD(secondNr, i, DBD);
		if (DBD == 1)
		{
			if (i == dal[0])
				cout << i;
			else
				cout << " " << i;
		}
	}
	return 0;
}
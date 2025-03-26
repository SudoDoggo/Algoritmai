#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DidBD(unsigned long long firstNr, unsigned long long secondNr, unsigned long long& DBD)
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
	cin >> firstNr;
	cin >> secondNr;
	unsigned long long DBD = 0;
	DidBD(firstNr, secondNr, DBD);
	cout << firstNr / DBD << " " << secondNr / DBD << endl;
	return 0;
}
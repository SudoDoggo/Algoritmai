#include <iostream>
#include <vector>
#include <algorithm>

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
	unsigned long long firstUp = 0;
	unsigned long long firstDown = 0;
	unsigned long long secondUp = 0;
	unsigned long long secondDown = 0;
	unsigned long long DBD = 0;
	cin >> firstUp >> firstDown >> secondUp >> secondDown;
	DidBD(firstDown, secondDown, DBD);
	unsigned long long MBK = (firstDown * secondDown) / DBD;
	firstUp = firstUp * (MBK / firstDown);
	secondUp = secondUp * (MBK / secondDown);
	unsigned long long suma = firstUp + secondUp;
	DidBD(suma, MBK, DBD);
	cout << suma /DBD << " " << MBK/DBD << endl;
	return 0;
}
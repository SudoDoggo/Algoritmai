#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long DidBD(unsigned long long firstNr, unsigned long long secondNr)
{
	while (firstNr != 0 && secondNr != 0)
	{
		if (firstNr > secondNr)
			firstNr %= secondNr;
		else
			secondNr %= firstNr;
	}
	if (firstNr == 0)
		return secondNr;
	else
		return firstNr;
}
int main()
{
	long long p = 0;
	long long q = 0;
	long long b = 0;
	long long dbd = 0;
	long long mbk = 0;
	short k = 0;
	vector<long long> v;
	cin >> p>>q;
	if (p == 1)
	{
		cout << 1 << endl;
		cout << p << "/" << q << endl;
		return 0;
	}
	while (k != 100)
	{
		k++;
		system("pause");
		if (q % p == 0)
			b = q / p;
		else
			b = q / p + 1;
		v.push_back(b);
		dbd = DidBD(q, b);
		mbk = b * q / dbd;
		p = p * (mbk / q);
		p -= (1 * (mbk / b));
		q = mbk;
		dbd = DidBD(p, q);
		p /= dbd;
		q /= dbd;
		if (p == 1)
		{
			v.push_back(q);
			break;
		}
		else if(p==0)
			break;
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (i == 0)cout << 1 << "/" << v[i];
		else cout<<" "<< 1 << "/" << v[i];
	}
	return 0;
}
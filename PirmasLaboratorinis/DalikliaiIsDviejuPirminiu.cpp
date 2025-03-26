#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int number)
{
	if (number == 1)
		return false;
	if (number == 2 || number == 3)
		return true;
	for (int i = 2; i <= sqrt(number); i++)
		if (number % i == 0) 
			return false;
	return true;
}
int DevideAmount(int number)
{
	int suma = 0;
	for (int i = 1; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			if (i != number / i)
				suma++;
			suma++;
		}
	}
	return suma;
}

void Checking(vector<int> primes, int amount, int number, bool& print)
{
	for (auto i : primes)
	{
		for (auto j:primes)
		{
			if (i * j == amount)
			{
				cout << number << " ";
				print = true;
				return;
			}
			if (i * j > amount) break;
		}
	}
}

int main()
{
	int firstNr, secondNr;
	cin >> firstNr >> secondNr;
	vector<int> primes;
	bool print = false;
	for (int i = 1; i <= sqrt(secondNr); i++)
		if (isPrime(i))
			primes.push_back(i);

	for (int i = firstNr; i <= secondNr; i++)
		Checking(primes, DevideAmount(i),i,print);
	if (!print)
		cout << 0 << endl;
	return 0;
}
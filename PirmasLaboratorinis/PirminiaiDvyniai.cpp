#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	long long n;
	cin >> n;
    bool prime = true;
    vector<long long> primes;
    bool twinPrimes = false;
    for (long long i = n; i <= 2*n; i++)
    {
        prime = true;
        for (long long j = 2; j <= sqrt(i); j++)
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        if (prime)
        {
            primes.push_back(i);
            if (primes.size() == 2)
            {
                if (primes[1] - primes[0] == 2)
                {
                    cout<<"YES";
                    return 0;
                }
            }
            else if (primes.size() >= 3)
            {
                if (primes.size() == 4)
                    primes.erase(primes.begin());
                if (primes[1] - primes[0] == 2||
                    primes[2] - primes[1] == 2||
                    primes[2] - primes[0] == 2)
                {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
    return 0;
}
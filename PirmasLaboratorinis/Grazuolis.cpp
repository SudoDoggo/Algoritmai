#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    long long lyginiuKiek = 0;
    long long nelyginiuKiek = 0;
    for (unsigned long long i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i % 2 == 0)
                lyginiuKiek++;
            else
                nelyginiuKiek++;
            if ((n / i) % 2 == 0)
                lyginiuKiek++;
            else
                nelyginiuKiek++;
        }
    }
    if (lyginiuKiek == nelyginiuKiek)
        cout << "TAIP";
    else
        cout << "NE";
    return 0;
}
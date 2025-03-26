#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
	long long n;
	cin >> n;
    stack<long long> stack;
    for (long long i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i != n / i)
                stack.push(n / i);
            stack.push(i);
        }
    }
    long long temp = 0;
    long long suma = 0;
    while (!stack.empty())
    {
        temp = stack.top();
        if (temp != n)
            suma += temp;
        stack.pop();
    }
    if (suma == n)
        cout << "TAIP";
    else
        cout << "NE";
    return 0;
}
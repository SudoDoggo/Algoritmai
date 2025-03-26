#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
	long long n;
	cin >> n;
    stack<long long> stack;
    if(n==1)
    {
        cout << 1;
        return 0;
    }
    for (long long i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            stack.push(i);
        }
    }
    int temp = 0;
    while (!stack.empty())
    {
        temp = stack.top();
        if (temp == 1)
            cout << n;
        else if ((n / temp) * (n / temp) != n)
            cout << n / temp << " ";
        stack.pop();
    }
    return 0;
}
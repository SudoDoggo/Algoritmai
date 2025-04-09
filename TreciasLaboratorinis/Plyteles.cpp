#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    long long dp[42];
    cin >> n;
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;
    for (int i = 4; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i-2]*4 + dp[i-3]*2;
    cout << dp[n];
    return 0;
}
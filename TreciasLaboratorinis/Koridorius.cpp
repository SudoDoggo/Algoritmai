#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    long long dp[101];
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 2;
    for (int i = 6; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 5];
    cout << dp[n];
    return 0;
}
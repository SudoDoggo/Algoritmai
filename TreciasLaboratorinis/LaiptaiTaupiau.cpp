#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long dp[4];
    dp[1%3] = 1;
    dp[2%3] = 2;
    dp[3%3] = 4;
    for (int i = 4; i <= n; i++)
    {
        dp[i % 3] = (dp[(i - 3) % 3] + dp[(i - 2) % 3] + dp[(i - 1) % 3])%1000000007;
    }
    cout << dp[n%3] << endl;
    return 0;
}
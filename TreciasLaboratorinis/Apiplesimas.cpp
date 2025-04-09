#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    long long dp[100001];
    int mas[100001];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> mas[i];
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    dp[1] = mas[1];
    dp[2] = max(mas[1], mas[2]);
    dp[3] = max({ mas[1], mas[2],mas[3] });
    for (int i = 4; i <= n; i++)
        dp[i] = max(dp[i - 1], dp[i - 3] + mas[i]);
    cout << dp[n];
    return 0;
}
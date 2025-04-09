#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    long long dp[4];
    vector<int> ind;
    int mas[100001];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> mas[i];
    if (n == 1)
    {
        cout << 0 << endl;
        cout << 0 << endl;
        return 0;
    }
    dp[1%3] = mas[1];
    dp[2%3] = max(mas[1], mas[2]);
    dp[3%3] = max({ mas[1], mas[2],mas[3] });
    for (int i = 4; i <= n; i++)
        dp[i%3] = max(dp[(i - 1) % 3], dp[(i - 3)%3] + mas[i]);
    long long maxRob = dp[n%3];
    int temp;
    for (int i = 1; i <= n; i++)
    {
        temp = mas[i];
        mas[i] = 0;
        dp[1 % 3] = mas[1];
        dp[2 % 3] = max(mas[1], mas[2]);
        dp[3 % 3] = max({ mas[1], mas[2],mas[3] });
        for (int j = 4; j <= n; j++)
            dp[j%3] = max(dp[(j - 1) % 3], dp[(j - 3) % 3] + mas[j]);
        if (dp[n % 3] != maxRob)
        {
            ind.push_back(i);
            mas[i] = temp;
            mas[i+1] = 0;
            i+=1;
        }
        else
        {
            mas[i] = 0;
        }
    }
    cout << maxRob << endl;
    cout << ind.size() << endl;
    for (int i = 0; i <ind.size(); i++)
    {
        if (i == 0)
            cout << ind[i];
        else
            cout << " " << ind[i];
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
void calculating(long long firstNr, long long secondNr, vector<long long> first, vector<long long> second)
{
    sort(first.begin(), first.end(), greater<int>());
    sort(second.begin(), second.end(), greater<int>());
    if (secondNr < firstNr)
    {
        for (auto j : second)
        {
            for (auto k : first)
            {
                if (j == k)
                {
                    cout << k << endl;
                    return;
                }
            }
        }
    }
    else
    {
        for (auto j : first)
        {
            for (auto k : second)
            {
                if (j == k)
                {
                    cout << k << endl;
                    return;
                }
            }
        }
    }
}
int main()
{
    int n;
    vector<long long> first;
    vector<long long> second;
    cin >> n;
    long long firstNr = 0;
    long long secondNr = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> firstNr;
        cin >> secondNr;
        first.clear();
        second.clear();
        if (secondNr == firstNr)
        {
            cout << firstNr << endl;
            continue;
        }
        for (long long j = 1; j <= sqrt(firstNr); j++)
        {
            if (firstNr % j == 0)
            {
                if (j != firstNr / j)
                    first.push_back(firstNr / j);
                first.push_back(j);
            }
        }
        for (long long j = 1; j <= sqrt(secondNr); j++)
        {
            if (secondNr % j == 0)
            {
                if (j != secondNr / j)
                    second.push_back(secondNr / j);
                second.push_back(j);
            }
        }
        calculating(firstNr, secondNr, first, second);
    }

	return 0;
}
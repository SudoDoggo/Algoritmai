#include <iostream>
#include <cmath>

using namespace std;
int kiek=0;
int maxx=-1;
int n;
int arr[101][101] = { 0 };
int U[101] = {};
void recursion(int u, int kiek)
{
    U[u] = 1;
    kiek++;
    for (int i = 1; i <= n; i++)
    {
        if (arr[u][i] == 1 && U[i] == 0)
        {
            recursion(i, kiek);
        }
    }
    if (kiek > maxx)
        maxx = kiek;
}
int main()
{
    cin >> n;
    int u;
    int v;
    int brKiek = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            if (j < i && arr[i][j] == 1)brKiek++;
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            U[j] = 0;
        kiek = 0;
        recursion(i, kiek);
        for (int j = 1; j <=n; j++)
            if (U[j] == 0)
            {
                cout << "No" << endl;
                return 0;
            }
    }
    if (brKiek + 1 == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
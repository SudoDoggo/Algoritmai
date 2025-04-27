#include <iostream>
#include <cmath>

using namespace std;
int kiek=0;
int maxx=-1;
int n;
int arr[1001][1001] = { 0 };
int U[1001] = {};
void recursion(int u, int kiek)
{
    U[u] = 1;
    kiek++;
    for (int i = 0; i <= n; i++)
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
    int m;
    cin >> n;
    cin >> m;
    int u;
    int v;
    int total = 0;
    for (int i = 1; i <=m; i++)
    {
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        total = 0;
        for (int i = 1; i <= n; i++)
            U[i] = 0;
        kiek = 0;
        recursion(i, kiek);
        for (int i = 1; i <= n; i++)
            if (U[i] == 1)
                total++;
        if (i == 1)
            cout << total;
        else
            cout << " " << total;
    }
    return 0;
}
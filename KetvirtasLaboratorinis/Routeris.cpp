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
    for (int i = 0; i < n; i++)
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
    int minMaxx = 1000;
    for (int i = 0; i <n-1; i++)
    {
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            U[j] = 0;
        kiek = 0;
        maxx = 0;
        recursion(i, kiek);
        if (maxx < minMaxx)
            minMaxx = maxx;
    }
    cout << minMaxx - 1 << endl;
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    int m;
    int u;
    int v;
    int arr[101][101] = { 0 };
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n;j++)
        {
            if (j == 1)
            {
                cout << arr[i][j];
            }
            else
            {
                cout <<" "<< arr[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
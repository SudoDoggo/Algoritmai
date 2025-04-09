#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int m;
    int plok[20][20];
    int PK[20][20];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> plok[i][j];
            if (i == 0)
            {
                if (j == 0)PK[i][j] = plok[i][j];
                else PK[i][j] = plok[i][j] + PK[i][j - 1];
            }
            else
            {
                if (j == 0)
                    PK[i][j] = plok[i][j] + PK[i - 1][j];
                else
                {
                    PK[i][j] = plok[i][j] + min(PK[i - 1][j],PK[i][j - 1]);
                }
            }
        }
    cout << PK[n - 1][m - 1];
    return 0;
}
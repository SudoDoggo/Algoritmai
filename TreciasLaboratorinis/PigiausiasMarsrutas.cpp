#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
short plok[1000][1000];
int PK[1000][1000];
char road[1000][1000];
int main()
{
    int n;
    char temp;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            plok[i][j] = (int)temp - 48;
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
                    PK[i][j] = plok[i][j] + min(PK[i - 1][j], PK[i][j - 1]);
            }
        }
    int i = n - 1;
    int j = n - 1;
    road[i][j] = '#';
    while (i != 0 && j != 0)
    {
        if (PK[i][j - 1] < PK[i - 1][j] || PK[i][j - 1] == PK[i - 1][j])
        {
            j--;
            road[i][j] = '#';
        }
        else if (PK[i][j - 1] > PK[i - 1][j])
        {
            i--;
            road[i][j] = '#';
        }
    }
    if (i == 0)
    {
        for (j; j >= 0; j--)
            road[i][j] = '#';
    }
    else if(j==0)
    {
        for (i; i >= 0; i--)
            road[i][j] = '#';
    }
    road[0][0] = '#';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (road[i][j] == '#')
                cout << road[i][j];
            else
                cout << '.';
        }
        cout << endl;
    }
    return 0;
}
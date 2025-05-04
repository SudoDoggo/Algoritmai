#include <iostream>
using namespace std;

int n,v,u, V[1001][1001] = {0}, U[1001] = {0};

void funk(int u)
{
    U[u]=1;
    for(int i=1; i<=n; i++)
    {
        if(V[u][i]==1 && U[i] == 0)
        {
            funk(i);
        }
    }
}
int main()
{
    int sum=0;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> V[i][j];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j <= n; j++)
            U[j] = 0;
        funk(i);
        for(int j=1; j <= n; j++)
            if(U[j] == 0)
            {
                cout<<"Ne";
                return 0;
            }
    }
    cout << "Taip";
    return 0;
}
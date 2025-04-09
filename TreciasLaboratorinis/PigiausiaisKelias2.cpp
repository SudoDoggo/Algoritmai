#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    int m;
    int plok;
    cin >> n >> m;
    vector<int> PK1(m,0);
    vector<int> PK2(m,0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> plok;
            if (i == 0)
            {
                if (j == 0)PK1[j]=plok;
                else PK1[j]=(plok+PK1[j - 1]);
            }
            else
            {
                if(i%2==0)
                {
                    if (j == 0)
                        PK1[j]=(plok + PK2[j]);
                    else
                    {
                        PK1[j]=(plok + min(PK2[j],PK1[j - 1]));
                    }
                }
                else
                {
                    if (j == 0)
                        PK2[j]=(plok + PK1[j]);
                    else
                    {
                        PK2[j]=(plok + min(PK1[j],PK2[j - 1]));
                    } 
                }
            }
        }
    if((n-1)%2==0)
        cout<<PK1[m-1];
    else
        cout<<PK2[m-1];
    cout<<endl;
    return 0;
}
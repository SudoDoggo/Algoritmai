#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int DP[4];
    cin>>n;
    DP[1%3]=0;
    DP[2%3]=1;
    DP[3%3]=1;
    for(int i=4;i<=n;i++)
    {
        DP[i%3]=(DP[(i-2)%3]+DP[(i-3)%3])%1000000007;
    }
    cout<<DP[n%3];
    return 0;
}
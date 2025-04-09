#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int skArr[100];
    int DP [100];
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>skArr[i];
    DP[0]=0;
    sort(skArr,skArr+n);
    DP[1]=skArr[1]-skArr[0];
    DP[2]=skArr[2]-skArr[1]+DP[1];
    for (int i = 3; i < n; i++)
        DP[i]=skArr[i]-skArr[i-1]+min(DP[i-1],DP[i-2]);
    cout<<DP[n-1]<<endl;
    return 0;
}
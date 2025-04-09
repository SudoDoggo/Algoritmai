#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    int temp=0;
    cin>>n;
    int k[2]={1,3};
    if(n==1)
        cout<<1<<endl;
    else if(n==2)
        cout<<3<<endl;
    else
    {
        for (int i = 3; i <= n; i++)
        {
            temp=k[0]+k[1];
            swap(k[0],k[1]);
            k[1]=temp;
        }
        cout<<k[1]<<endl;
    }
    
}
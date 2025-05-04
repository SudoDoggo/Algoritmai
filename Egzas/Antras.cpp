#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int DBD(int a, int b)
{
    while(a!=0&&b!=0)
    {
        if(a>b)
            a=a%b;
        else
            b=b%a;
    }
    if(a==0)
        return b;
    else
        return a;
}
int main()
{
int a;
int b;
cin>>a>>b;
cout<<((a+b)/DBD(a,b))-2;
}
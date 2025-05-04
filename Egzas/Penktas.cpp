#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    double a;
	cin >> a;
    double mid=0;
    double x=0;
    double left=0;
    double right = a;
    for (size_t i = 0; i <= 100; i++)
    {
        mid=(left+right)/2;
        x=mid+cbrt(mid);
        if(x==a)break;
        else if(x<a)
            left=mid;
        else
            right=mid;
    }
    cout<<fixed<<setprecision(5)<<mid<<endl;
	return 0;
}
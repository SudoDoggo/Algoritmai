#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long BinarySearch(long long check)
{
	long long mid=0;
    long long left=0;
    long long right = check;
    long long taur=0;
    while(left<=right)
    {
        mid = (left+right)/2;
        taur=0.5*mid*(mid+1);
        if(taur>check)
            right=mid-1;
        else
            left=mid+1;
    }
    if(left>right)
        return right;
    else
        return left;

}
int main()
{
	long long n = 0;
	cin >> n;
	cout<<BinarySearch(n) << endl;
	return 0;
}
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double BinarySearch(long long check)
{
	double left = 0;
	double middle = 0;
	double right = 20000;
	long long squere = 0;
	for (int i = 0; i < 100; i++)
	{
		middle = (right + left) / 2.0;
		squere = 0;
		for (int i = 1; i <= middle; i++)
			squere += (int)sqrt(middle * middle - i * i);
		squere *= 4;
		if (squere >check)
			right = middle;
		else
			left = middle;
	}
	return middle;
}
int main()
{
	long long look = 0;
	cin >> look;
	cout<<setprecision(10)<<fixed<<BinarySearch(look);
	return 0;
}
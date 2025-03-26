#include <iostream>
#include <iomanip>

using namespace std;

double BinarySearch(int check)
{
	double left = 0;
	double middle = 0;
	double right = check;
	for (int i = 0; i < 100; i++)
	{
		middle = (right + left) / 2.0;
		if (middle + (check - middle) == check && middle * (check - middle) == check)
			return middle;
		else if (middle * (check - middle) > check)
			right = middle;
		else
			left = middle;
	}
	return middle;
}
int main()
{
	int look = 0;
	cin >> look;
	double a = BinarySearch(look);
	if (look-(a * (look - a))<0.00000001)
		cout << setprecision(7) << fixed << a << " " << look - a;
	else
		cout << "NERA";
	return 0;
}
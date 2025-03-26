#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main()
{
	int p, q, r, s, t, u;
	double left = 0;
	double middle = 0;
	double right = 1;
	double calc = 0;
	while (cin >> p >> q >> r >> s >> t >> u)
	{
		left = 0;
		right = 1;
		if (p * exp(-left) + q * sin(left) + r * cos(left) + s * tan(left) + t * left * left + u < 0
			&& p * exp(-right) + q * sin(right) + r * cos(right) + s * tan(right) + t * right * right + u < 0 ||
			p * exp(-left) + q * sin(left) + r * cos(left) + s * tan(left) + t * left * left + u > 0
			&& p * exp(-right) + q * sin(right) + r * cos(right) + s * tan(right) + t * right * right + u > 0)
		{
			cout << "No solution" << endl;
			continue;
		}
		for (int i = 0; i < 100; i++)
		{
			middle = (right + left) / 2.0;
			calc = p * exp(-middle) + q * sin(middle) + r * cos(middle) + s * tan(middle) + t * middle * middle + u;
			if (calc < 0)
				right = middle;
			else
				left = middle;
		}
		if (calc > 0.000000001)
		{
			cout << "No solution" << endl;
		}
		else
			cout << setprecision(4) << fixed << middle << endl;
	}
	return 0;
}
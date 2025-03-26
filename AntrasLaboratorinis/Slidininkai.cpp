#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	vector<int> a;
	vector<int> b;
	int temp;
	double suma=0;
	double pi;
	double calc;
	double calcskir;
	double ind;
	cin >> n;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			if (i == 0)
				a.push_back(temp);
			else
				b.push_back(temp);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++)
	{
		calcskir = a[i] - b[i];
		if (calcskir < 0)calcskir *= -1;
		suma += calcskir;
	}
	cout<<setprecision(9)<<fixed << 1.0 / n * suma << endl;
	return 0;
}
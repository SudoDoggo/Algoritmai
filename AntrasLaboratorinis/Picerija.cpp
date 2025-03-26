#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	double pi = 355.0 / 113;
	vector<int> R;
	vector<int> S;
	int n = 0;
	vector<double>picKaina;
	double x = 0;
	double suma = 0;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		R.push_back(temp);
		cin >> temp;
		S.push_back(temp);
		picKaina.push_back(R[i]/2.0 * R[i]/2.0 * pi/S[i]);
	}
	double max = 0;
	while(x>0&&picKaina.size()!=0)
	{
		int ind = 0;
		max = 0;
		for (int j = 0; j < picKaina.size(); j++)
		{
			if (max < picKaina[j])
			{
				max = picKaina[j];
				ind = j;
			}
		}
		if (x >=S[ind])
		{
			x -= S[ind];
			suma += R[ind] / 2.0 * R[ind] / 2.0 * pi;
			picKaina.erase(picKaina.begin() + ind);
			R.erase(R.begin() + ind);
			S.erase(S.begin() + ind);
		}
		else if(x!=0)
		{
			double kiekgali = (double)x / S[ind];
			suma += kiekgali * R[ind] / 2.0 * R[ind] / 2.0 * pi;
			picKaina.erase(picKaina.begin() + ind);
			R.erase(R.begin() + ind);
			S.erase(S.begin() + ind);
			x = 0;
		}
	}
	cout <<setprecision(3)<<fixed<< suma << endl;
	return 0;
}
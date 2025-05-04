#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
int n;
cin>> n;
vector<int> dalikliai;

for (int i = 1; i <=sqrt(n); i++)
{
    if(n%i==0)
    {
        dalikliai.push_back(i);
        if(i != n/i)
        {
            dalikliai.push_back(n/i);
        }
    }
}
sort(dalikliai.begin(), dalikliai.end());
cout<<dalikliai[dalikliai.size()-3];
}
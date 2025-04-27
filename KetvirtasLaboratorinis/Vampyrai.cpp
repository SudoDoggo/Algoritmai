#include <iostream>
#include <cmath>
#include <queue>

using namespace std;
int kiek=0;
int maxx=-1;
int n;
int m;
char map[2002][2002] = {'#'};
queue < pair<int, int>>vampires;
int main()
{
    cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			if(map[i][j]=='V')
				vampires.push(make_pair(i, j));
		}
	int size = 0;
	while (!vampires.empty())
	{
		kiek++;
		size = vampires.size();
		for (int i = 0; i < size; i++)
		{
			if (map[vampires.front().first][(vampires.front().second) + 1] == '.')
			{
				map[vampires.front().first][(vampires.front().second) + 1] = kiek + 48;
				vampires.push(make_pair(vampires.front().first, (vampires.front().second) + 1));
			}
			if (map[vampires.front().first][(vampires.front().second) - 1] == '.')
			{
				map[vampires.front().first][(vampires.front().second) - 1] = kiek + 48;
				vampires.push(make_pair(vampires.front().first, (vampires.front().second) - 1));
			}
			if (map[(vampires.front().first) + 1][vampires.front().second] == '.')
			{
				map[(vampires.front().first) + 1][vampires.front().second] = kiek + 48;
				vampires.push(make_pair((vampires.front().first) + 1, vampires.front().second));
			}
			if (map[(vampires.front().first) - 1][vampires.front().second] == '.')
			{
				map[(vampires.front().first) - 1][vampires.front().second] = kiek + 48;
				vampires.push(make_pair((vampires.front().first) - 1, vampires.front().second));
			}
			vampires.pop();
		}
	}
	cout << kiek-1 << endl;
    return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
int kiek=0;
int maxx=-1;
int n;
int m;
char map[1002][1002] = {'#'};
queue < pair<int, int>>pos;
int main()
{
    cin >> n >> m;
	vector<char> road;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			if(map[i][j]=='A')
				pos.push(make_pair(i, j));
		}
	int size = 0;
	while (!pos.empty())
	{
		kiek++;
		size = pos.size();
		for (int i = 0; i < size; i++)
		{
			if (map[pos.front().first][(pos.front().second) + 1] == 'B')
			{
				road.push_back('R');
				cout << "YES" << endl;
				cout << kiek<< endl;
				int x = pos.front().first;
				int y = (pos.front().second) + 1;
				for (int j = road.size() - 1; j > 0; j--)
				{
					if (road[j] == 'D' && map[x - 1][y] == kiek + 47)
					{
						cout << 'D';
						kiek--;
					}
					if (road[j] == 'U' && map[x + 1][y] == kiek + 47)
					{
						cout << 'U';
						kiek--;
					}
					if (road[j] == 'R' && map[x][y-1] == kiek + 47)
					{
						cout << 'R';
						kiek--;
					}
					if (road[j] == 'L' && map[x][y+1] == kiek + 47)
					{
						cout << 'L';
						kiek--;
					}
				}
				return 0;
			}
			if (map[pos.front().first][(pos.front().second) - 1] == 'B')
			{
				road.push_back('L');
				cout << "YES" << endl;
				cout << kiek<< endl;
				int x = pos.front().first;
				int y = (pos.front().second) - 1;
				for (int j = road.size() - 1; j > 0; j--)
				{
					if (road[j] == 'D' && map[x - 1][y] == kiek + 47)
					{
						cout << 'D';
						kiek--;
					}
					if (road[j] == 'U' && map[x + 1][y] == kiek + 47)
					{
						cout << 'U';
						kiek--;
					}
					if (road[j] == 'R' && map[x][y - 1] == kiek + 47)
					{
						cout << 'R';
						kiek--;
					}
					if (road[j] == 'L' && map[x][y + 1] == kiek + 47)
					{
						cout << 'L';
						kiek--;
					}
				}
				return 0;
			}
			if (map[(pos.front().first) + 1][pos.front().second] == 'B')
			{
				road.push_back('D');
				cout << "YES" << endl;
				cout << kiek << endl;
				int x = (pos.front().first) + 1;
				int y = (pos.front().second);
				for (int j = road.size() - 1; j > 0; j--)
				{
					if (road[j] == 'D' && map[x - 1][y] == kiek + 47)
					{
						cout << 'D';
						kiek--;
					}
					if (road[j] == 'U' && map[x + 1][y] == kiek + 47)
					{
						cout << 'U';
						kiek--;
					}
					if (road[j] == 'R' && map[x][y - 1] == kiek + 47)
					{
						cout << 'R';
						kiek--;
					}
					if (road[j] == 'L' && map[x][y + 1] == kiek + 47)
					{
						cout << 'L';
						kiek--;
					}
				}
				return 0;
			}
			if (map[(pos.front().first) - 1][(pos.front().second)] == 'B')
			{
				road.push_back('U');
				cout << "YES" << endl;
				cout << kiek << endl;
				int x = (pos.front().first) - 1;
				int y = (pos.front().second);
				for (int j = road.size() - 1; j > 0; j--)
				{
					if (road[j] == 'D' && map[x - 1][y] == kiek + 47)
					{
						cout << 'D';
						kiek--;
					}
					if (road[j] == 'U' && map[x + 1][y] == kiek + 47)
					{
						cout << 'U';
						kiek--;
					}
					if (road[j] == 'R' && map[x][y - 1] == kiek + 47)
					{
						cout << 'R';
						kiek--;
					}
					if (road[j] == 'L' && map[x][y + 1] == kiek + 47)
					{
						cout << 'L';
						kiek--;
					}
				}
				return 0;
			}
			if (map[pos.front().first][(pos.front().second) + 1] == '.')
			{
				map[pos.front().first][(pos.front().second) + 1] = kiek + 48;
				pos.push(make_pair(pos.front().first, (pos.front().second) + 1));
				road.push_back('R');
			}
			if (map[pos.front().first][(pos.front().second) - 1] == '.')
			{
				map[pos.front().first][(pos.front().second) - 1] = kiek + 48;
				pos.push(make_pair(pos.front().first, (pos.front().second) - 1));
				road.push_back('L');
			}
			if (map[(pos.front().first) + 1][pos.front().second] == '.')
			{
				map[(pos.front().first) + 1][pos.front().second] = kiek + 48;
				pos.push(make_pair((pos.front().first) + 1, pos.front().second));
				road.push_back('D');
			}
			if (map[(pos.front().first) - 1][pos.front().second] == '.')
			{
				map[(pos.front().first) - 1][pos.front().second] = kiek + 48;
				pos.push(make_pair((pos.front().first) - 1, pos.front().second));
				road.push_back('U');
			}
			pos.pop();
		}

	}
    return 0;
}
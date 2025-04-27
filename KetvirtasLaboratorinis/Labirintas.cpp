#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;
int kiek = 0;
int maxx = -1;
int n;
int m;
string map[1002][1002] = { "#" };
queue < pair<int, int>>pos;
void RoadPrint(vector<char> road, int kiekis, int x, int y)
{
	cout << "YES" << endl;
	cout << kiek << endl;
	kiek--;
	stack<char> roadBack;
	for (int j = road.size() - 1; j >= 0; j--)
	{
		if (road[j] == 'D' && map[x - 1][y] == to_string(kiek) || map[x - 1][y] == "A")
		{
			roadBack.push('D');
			x--;
			kiek--;
		}
		if (road[j] == 'U' && map[x + 1][y] == to_string(kiek) || map[x + 1][y] == "A")
		{
			roadBack.push('U');
			x++;
			kiek--;
		}
		if (road[j] == 'R' && map[x][y - 1] == to_string(kiek) || map[x][y - 1] == "A")
		{
			roadBack.push('R');
			y--;
			kiek--;
		}
		if (road[j] == 'L' && map[x][y + 1] == to_string(kiek) || map[x][y + 1] == "A")
		{
			roadBack.push('L');
			y++;
			kiek--;
		}
	}
	while (!roadBack.empty())
	{
		cout << roadBack.top();
		roadBack.pop();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	vector<char> road;
	char temp;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> temp;
			map[i][j] = temp;
			if (map[i][j] == "A")
				pos.push(make_pair(i, j));
		}
	int size = 0;
	while (!pos.empty())
	{
		kiek++;
		size = pos.size();
		for (int i = 0; i < size; i++)
		{
			if (map[pos.front().first][(pos.front().second) + 1] == "B")
			{
				road.push_back('R');
				RoadPrint(road, kiek, (pos.front().first), (pos.front().second) + 1);
				return 0;
			}
			if (map[pos.front().first][(pos.front().second) - 1] == "B")
			{
				road.push_back('L');
				RoadPrint(road, kiek, (pos.front().first), (pos.front().second) - 1);
				return 0;
			}
			if (map[(pos.front().first) + 1][pos.front().second] == "B")
			{
				road.push_back('D');
				RoadPrint(road, kiek, (pos.front().first) + 1, (pos.front().second));
				return 0;
			}
			if (map[(pos.front().first) - 1][(pos.front().second)] == "B")
			{
				road.push_back('U');
				RoadPrint(road, kiek, (pos.front().first) - 1, (pos.front().second));
				return 0;
			}
			if (map[pos.front().first][(pos.front().second) + 1] == ".")
			{
				map[pos.front().first][(pos.front().second) + 1] = to_string(kiek);
				pos.push(make_pair(pos.front().first, (pos.front().second) + 1));
				road.push_back('R');
			}
			if (map[pos.front().first][(pos.front().second) - 1] == ".")
			{
				map[pos.front().first][(pos.front().second) - 1] = to_string(kiek);
				pos.push(make_pair(pos.front().first, (pos.front().second) - 1));
				road.push_back('L');
			}
			if (map[(pos.front().first) + 1][pos.front().second] == ".")
			{
				map[(pos.front().first) + 1][pos.front().second] = to_string(kiek);
				pos.push(make_pair((pos.front().first) + 1, pos.front().second));
				road.push_back('D');
			}
			if (map[(pos.front().first) - 1][pos.front().second] == ".")
			{
				map[(pos.front().first) - 1][pos.front().second] = to_string(kiek);
				pos.push(make_pair((pos.front().first) - 1, pos.front().second));
				road.push_back('U');
			}
			pos.pop();
		}
	}
	cout << "NO" << endl;
	return 0;
}
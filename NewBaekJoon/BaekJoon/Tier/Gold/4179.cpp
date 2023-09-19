#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int R, C;
vector<vector<char>>map;
vector<vector<int>>sum;

queue<pair<int, int>>q;
queue<pair<int, int>>F;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0 ,0 };

void FireSetting()
{
	int size = F.size();
	int y, x;
	for (int i = 0; i < size; i++)
	{
		tie(y, x) = F.front(); F.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if (map[ny][nx] == '#' || map[ny][nx] == 'F') continue;
			F.push({ ny,nx });
			map[ny][nx] = 'F';
		}
	}
}


int main()
{
	int i, j;

	cin >> R >> C;

	map.assign(R, vector<char>(C));
	sum.assign(R, vector<int>(C, 0));

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				q.push({ i,j });
				sum[i][j] = 1;
			}
			else if (map[i][j] == 'F')
				F.push({ i,j });
		}
	}


	bool flag = false;
	int res;

	int y, x;
	while (!q.empty())
	{
		FireSetting(); // ºÒ ¹øÁü ¼¼ÆÃ

		int size = q.size();

		for (i = 0; i < size; i++)
		{
			tie(y, x) = q.front(); q.pop();
			if ((y == 0 || y == R - 1) || (x == 0 || x == C - 1))
			{
				flag = true;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
				if (map[ny][nx] == '#' || map[ny][nx] == 'F' || sum[ny][nx]) continue;
				q.push({ ny,nx });
				sum[ny][nx] = sum[y][x] + 1;
			}
		}
		if (flag) break;
	}

	if (!flag) cout << "IMPOSSIBLE";
	else cout << sum[y][x];

}
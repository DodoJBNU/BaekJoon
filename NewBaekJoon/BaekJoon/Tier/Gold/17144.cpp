#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pair<int, int>cleaner;

	int res = 0;
	int dx[] = { 0,0, -1,1 };
	int dy[] = { -1,1, 0 ,0 };
	int r, c, t;
	int i, j;
	cin >> r >> c >> t;

	vector<vector<int>>map(r + 1, vector<int>(c + 1, 0));
	vector<vector<int>>temp(r + 1, vector<int>(c + 1, 0));

	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				cleaner.first = i-1; // 공기청정기 위쪽 좌표. column은 1 고정.
				cleaner.second = i; // 공기청정기의 아래쪽 좌표가 찍힐 것임.
			}
		}
	}
	
	for (int q = 0; q < t; q++)
	{
		temp.assign(r + 1, vector<int>(c + 1, 0));
		for (i = 1; i <= r; i++) // 미세먼지 확산.
		{
			for (j = 1; j <= c; j++)
			{
				if (map[i][j] == 0) continue; // 미세먼지 없으면 continue
				int cnt = 0;
				int new_dust = map[i][j] / 5;
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					if ((ny <= 0 || nx <= 0) || (ny > r || nx > c) || map[ny][nx] == -1)
						continue;
					// 범위에서 벗어나거나, 공기청정기 안이라면, continue
					cnt++; // 유효한 범위면 cnt++
					temp[ny][nx] += new_dust;
				}
				map[i][j] = map[i][j] - (new_dust * cnt);
			}
		}

		for (i = 1; i <= r; i++)
		{
			for (j = 1; j <= c; j++)
			{
				map[i][j] += temp[i][j];
			}
		}

		// 공기청정기 작동

		int c_y = cleaner.first;
		int c_x = 2; // (공기청정기 r 좌표, 2)에서 시작.

		// 공기청정기 위쪽.
		int b_tmp = 0;
		int n_tmp;
		while (1)
		{
			if (c_y == cleaner.first && c_x == 1) break;
			n_tmp = map[c_y][c_x];
			map[c_y][c_x] = b_tmp;
			b_tmp = n_tmp;

			// 다음 위치로 이동
			if (c_y == cleaner.first)
			{
				if (c_x == c)
					c_y--;
				else
					c_x++;
			}
			else if (c_y == 1)
			{
				if (c_x == 1)
					c_y++;
				else
					c_x--;
			}
			else
			{
				if (c_x == 1)
					c_y++;
				else
					c_y--;
			}
		}

		// 공기청정기 아래쪽


		c_y = cleaner.second;
		c_x = 2; // (공기청정기 r 좌표, 2)에서 시작.

		b_tmp = 0;
		while (1)
		{
			if (c_y == cleaner.second && c_x == 1) break;
			n_tmp = map[c_y][c_x];
			map[c_y][c_x] = b_tmp;
			b_tmp = n_tmp;

			// 다음 위치로 이동
			if (c_y == cleaner.second)
			{
				if (c_x == c)
					c_y++;
				else
					c_x++;
			}
			else if (c_y == r)
			{
				if (c_x == 1)
					c_y--;
				else
					c_x--;
			}
			else
			{
				if (c_x == 1)
					c_y--;
				else
					c_y++;
			}
		}



	}// 미세먼지


	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (map[i][j] != -1)
				res += map[i][j];
		}
	}

	cout << res;
	return 0;
}
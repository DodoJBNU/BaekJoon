#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int dy[] = {0, 0 , -1, 1};
	int dx[] = { -1, 1, 0, 0 };
	int y, x;
	int N, i , j, max = 0, k, u;
	int res = 0, cnt = 0; 
	cin >> N;
	vector<vector<int>>map(N, vector<int>(N));
	vector<vector<bool>>visited(N, vector<bool>(N));
	queue<pair<int, int>>q;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > max)
				max = map[i][j];
		}
	}
	
	for (k = 0; k < max; k++)
	{
		visited.assign(N, vector<bool>(N, false));
		cnt = 0;
		for (i = 0; i < N; i++) 
		{
			for (j = 0; j < N; j++)
			{	
				if (map[i][j] > k && !visited[i][j])
				{
					cnt++;
					visited[i][j] = true;

					q.push(pair<int, int>(i, j));
					while (!q.empty())
					{
						tie(y, x) = q.front(); q.pop();

						for (u = 0; u < 4; u++)
						{
							int ny = dy[u] + y;
							int nx = dx[u] + x;

							if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
							if (map[ny][nx] <= k || visited[ny][nx]) continue;

							visited[ny][nx] = true;
							q.push(pair<int, int>(ny, nx));
						}
					}
				}

			}
		}

		res = std::max(res, cnt);
	}

	cout << res;
	return 0;
}
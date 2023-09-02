#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<cmath>
using namespace std;

int main()

	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool flag;
	int day = -1, cnt;
	int dy[]  = {0, 0, 1, -1};
	int dx[] = { 1, -1, 0, 0 };
	int N, R, L;
	int i, j, x, y, k;
	queue<pair<int, int>> q;
	cin >> N >> L >> R;
	
	vector<vector<pair<int, int>>> chain(N);
	vector<vector<int>>A(N, vector<int>(N));
	vector<vector<bool>>visited(N, vector<bool>(N));
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> A[i][j];

	while (1)
	{
		flag = false;
		day++;
		vector<vector<pair<int, int>>> chain(N*N);
		cnt = -1;
		visited.assign(N, vector<bool>(N, false));

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					cnt++;
					q.push(pair<int, int>(i, j));
					chain[cnt].push_back(pair<int, int>(i, j));

					visited[i][j] = true;
					while (!q.empty())
					{
						tie(y, x) = q.front(); q.pop();

						for (k = 0; k < 4; k++)
						{
							int ny = dy[k] + y;
							int nx = dx[k] + x;


							if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
							int diff = abs(A[ny][nx] - A[y][x]);
							if (diff < L
								|| diff > R
								|| visited[ny][nx]) continue;

							visited[ny][nx] = true;
							q.push(pair<int, int>(ny, nx));
							chain[cnt].push_back(pair<int, int>(ny, nx));
						}
					}
				}
			}
		}

		for (auto k : chain)
		{
			int sum = 0;
			if (k.size() >= 2)
			{
				flag = true;
				for (auto u : k)
				{
					tie(y, x) = u;
					sum += A[y][x];
				}

				int temp = floor(sum / k.size());

				for (auto u : k)
				{
					tie(y, x) = u;
					A[y][x] = temp;
				}
			}
		}

		if (!flag) break;
	}
	
		cout << day;
	return 0;
}
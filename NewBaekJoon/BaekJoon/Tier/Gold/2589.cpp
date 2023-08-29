#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, i, j;
	int ny, nx, y, x;
	int res = 0;
	char input;
	int dy[4] = { 0, 0, 1, -1 };
	int dx[4] = { 1, -1, 0, 0 };
	
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<vector<int>> sum;
	vector<pair<int,int>> keep;
	queue<pair<int, int>> Q;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> input;
			if (input == 'L')
			{
				map[i][j] = 1;
				keep.push_back(pair<int, int>(i, j));
			}
		}
	}

	for (auto cur : keep)
	{
		sum.assign(n, vector<int>(m, 0));

		tie(y, x) = cur;
		sum[y][x] = 1; // 초기값은 1로 설정.
		Q.push(pair<int,int>(y, x));
		while (!Q.empty())
		{
			tie(y, x) = Q.front(); Q.pop();

			for (i = 0; i < 4; i++)
			{
				ny = y + dy[i];
				nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if (!map[ny][nx] || sum[ny][nx]) continue;

				Q.push(make_pair(ny, nx));
				sum[ny][nx] = sum[y][x] + 1;
				
				res = max(res, sum[ny][nx]);
			}
		}
	}

	cout << res - 1;
	return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N, K;
	int y, x;
	cin >> M >> N >> K;

	int dy[] = { 0, 0, 1, -1 };
	int dx[] = { 1, -1, 0 , 0 };
	vector<vector<int>>input(K, vector<int>(4));
	vector<int>res;
	vector<vector<int>>map(M, vector<int>(N, 0));
	vector<vector<int>>sum(M, vector<int>(N, 0));
	queue<pair<int, int>> q;

	for (int i = 0; i < K; i++)
		for (int j = 0; j < 4; j++)
			cin >> input[i][j];
	
	for (int k = 0; k < K; k++)
	{
		for (int i = input[k][1]; i < input[k][3]; i++)
		{
			for (int j = input[k][0]; j < input[k][2]; j++)
			{
				if (!map[i][j])
					map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!map[i][j] && !sum[i][j])
			{
				q.push({ i, j });

				sum[i][j] = 1;
				int temp = 0;
				while (!q.empty())
				{
					temp++;
					tie(y, x) = q.front(); q.pop();
					
					for (int i = 0; i < 4; i++)
					{
						int n_y = y + dy[i];
						int n_x = x + dx[i];

						if (n_y < 0 || n_x < 0 || n_y >= M || n_x >= N) continue;
						if (map[n_y][n_x] || sum[n_y][n_x]) continue;

						q.push({ n_y, n_x });
						sum[n_y][n_x] = sum[y][x] + 1;
					}			
				}
				res.push_back(temp);
			}
		}
	}

	sort(res.begin(), res.end());

	cout << res.size() << "\n";
	for (auto r : res)
		cout << r << " ";
	return 0;
}

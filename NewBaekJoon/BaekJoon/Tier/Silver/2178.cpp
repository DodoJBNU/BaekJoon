#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int i, j;
	cin >> N >> M;

	vector<vector<char>> maze(N + 1, vector<char>(M + 1, '0'));
	vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));
	vector<vector<int>> sum(N + 1, vector<int>(M + 1, 0));
	int directed[4][2] = {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};

	queue<pair<int, int>> q;
	pair<int, int> cur;

	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			cin >> maze[i][j];


	q.push(make_pair(1, 1));
	visited[1][1] = true;
	sum[1][1] = 1;
	while (1)
	{
		cur = q.front();
		q.pop();

		if (cur.first == N && cur.second == M)
			break;
		for (auto d : directed)
		{
			int next_x = cur.first + d[0];
			int next_y = cur.second + d[1];
			if (next_x > 0 && next_y > 0
				&& next_x <= N && next_y <= M
				&& !visited[next_x][next_y]
				&& maze[next_x][next_y] == '1')
			{
				q.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = true;
				sum[next_x][next_y] = sum[cur.first][cur.second] + 1;
			}
		}
	}

	cout << sum[N][M];
	return 0;
}
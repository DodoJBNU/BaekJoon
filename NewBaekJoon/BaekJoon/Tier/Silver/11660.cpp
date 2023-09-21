#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<vector<int>>map;
vector<vector<int>>dp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	map.assign(N+1, vector<int>(N+1,0));
	dp.assign(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + map[i][j];
		}
	}
	

	for (int k = 0; k < M; k++)
	{
		int x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		int res = dp[y2][x2] - (dp[y2][x1-1] + dp[y1-1][x2]) + dp[y1-1][x1-1];
		cout << res << "\n";
	}

	return 0;
}
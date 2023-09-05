#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;
	vector<vector<int>>rgb(N+1, vector<int>(3,0));
	vector<vector<int>>dp(N + 1, vector<int>(3,0));

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			cin >> rgb[i][j];

	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
	}

	int res = min({ dp[N][0] , dp[N][1], dp[N][2] });

	cout << res;
	return 0;
}
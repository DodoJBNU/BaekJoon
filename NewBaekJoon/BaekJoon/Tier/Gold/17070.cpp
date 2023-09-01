#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
bool map[16][16];
int ans[16][16][3];  // [0] : 가로 [1]: 대각 [2]: 세로

void solve()
{
	ans[0][1][0] = 1;

	for (int j = 2; j < N; j++)
	{
		if (!map[0][j]) // 벽이 아니면
		{
			ans[0][j][0] = ans[0][j - 1][0];
		}
		else
			break;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 2; j < N; j++)
		{
			if (!map[i][j])
			{
				ans[i][j][0] = ans[i][j - 1][0] + ans[i][j - 1][1];
				ans[i][j][2] = ans[i - 1][j][1] + ans[i - 1][j][2];

				if (!map[i-1][j] && !map[i][j-1])
				{
					ans[i][j][1] = ans[i - 1][j - 1][0] + ans[i - 1][j - 1][1] + ans[i - 1][j - 1][2];
				}
			}
		}

	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	solve();

	int sum =
		ans[N - 1][N - 1][0] + ans[N - 1][N - 1][1] + ans[N - 1][N - 1][2];

	cout << sum;

	return 0;
}
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int res = 1;
	cin >> N;
	vector<int>arr(N, 0);
	vector<int>dp(N, 1);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
				dp[i] = std::max(dp[j] + 1, dp[i]);
		}
		res = std::max(res, dp[i]);
	}
	
	cout << res;
	return 0;
}
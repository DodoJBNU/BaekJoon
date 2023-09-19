#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int>input;
vector<int>res;

void dfs(int depth)
{
	if (depth == M)
	{
		for (auto i : res)
		{
			cout << i << " ";
		}
		cout << "\n";
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (depth == 0 || res[depth - 1] <= input[i])
			{
				res[depth] = input[i];
				dfs(depth + 1);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	input.assign(N, 0);
	res.assign(M, 0);

	for (int i = 0; i < N; i++)
		cin >> input[i];

	sort(input.begin(), input.end());
	dfs(0);
	return 0;
}
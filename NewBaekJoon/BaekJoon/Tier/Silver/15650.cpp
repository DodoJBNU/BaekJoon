#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int>input;
vector<bool>visited;

void dfs(int depth, int start)
{
	if (depth == M)
	{
		for (auto i : input)
		{
			cout << i << " ";
		}
		cout << "\n";
	}
	else
	{
		for (int i = start; i <= N; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				input[depth] = i;
				dfs(depth + 1, i+1);
				visited[i] = false;
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

	input.assign(M, 0);
	visited.assign(N + 1, false);

	dfs(0, 1);
	return 0;
}
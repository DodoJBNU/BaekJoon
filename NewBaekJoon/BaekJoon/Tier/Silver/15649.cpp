#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int>input;
vector<bool>visited;

void dfs(int depth)
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
		for (int i = 1; i <= N; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				input[depth] = i;
				dfs(depth + 1);
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
	visited.assign(N + 1, false);
	input.assign(M, 0);

	dfs(0);
	return 0;
}
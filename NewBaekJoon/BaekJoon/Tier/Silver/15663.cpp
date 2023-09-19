#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int> res;
vector<int>input;
vector<bool>visited;

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
			if (!visited[input[i]])
			{
				visited[input[i]] = true;
				res[depth] = input[i];
				dfs(depth + 1);
				visited[input[i]] = false;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int max = -1;
	cin >> N >> M;
	input.assign(N, 0);
	res.assign(M, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
		max = std::max(input[i], max);
	}

	sort(input.begin(), input.end());
	visited.assign(max+1, false);
	
	dfs(0);
	return 0;
}
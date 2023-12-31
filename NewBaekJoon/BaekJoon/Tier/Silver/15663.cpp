#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;

vector<int>last;
vector<int>input;
vector<int>res;
vector<bool>visited;

void dfs(int depth)
{
	if (depth == M)
	{
		bool flag = false;

		if (!last.empty())
		{
			for (int i = 0; i < last.size(); i++)
			{
				if (last[i] != res[i])
				{
					flag = true;
					break;
				}
			}
		}
		else flag = true;

		if (flag)
		{
			last = res;
			for (auto i : res)
			{
				cout << i << " ";
			}
			cout << "\n";
		}
	}
	else
	{
		int temp = 0;
		for (int i = 0; i < N; i++)
		{
			if (input[i]!=temp && !visited[i])
			{
				res[depth] = input[i];
				temp = input[i];
				visited[i] = true;
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
	input.assign(N, 0);
	res.assign(M, 0);	
	visited.assign(N, false);

	for (int i = 0; i < N; i++)
		cin >> input[i];

	sort(input.begin(), input.end());
	
	dfs(0);
	return 0;
}
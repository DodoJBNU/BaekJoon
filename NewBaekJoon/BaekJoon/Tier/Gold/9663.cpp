#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
int sum;
vector<int>num;

void dfs(int depth)
{
	if (depth == N)
		sum++;
	else
	{
		for (int j = 0; j < N; j++)
		{
			bool flag = true;
			for (int k = 0; k < depth; k++)
			{
				int diff = abs(num[k] - j);

				if (diff == 0 || abs(k-depth) == diff)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				num[depth] = j;
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

	cin >> N;

	num.assign(N, 0);
	dfs(0);
	cout << sum;
	return 0;
}
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, M, N, K;
	int i, j, u;
	cin >> T;
	vector<vector<int>>cab;
	vector<vector<int>>visited;
	vector<pair<int, int>>directed =
	{
		make_pair(0,1),
		make_pair(0,-1),
		make_pair(1,0),
		make_pair(-1,0),
	};

	stack<pair<int,int>> s;

	for (i = 0; i < T; i++) // Test Case °³¼ö
	{
		cin >> M >> N >> K;
		int sum = 0;
		cab.assign(N, vector<int>(M, 0));
		visited.assign(N, vector<int>(M, 0));

		pair<int, int> temp;
		for (j = 0; j < K; j++)
		{
			cin >> temp.first >> temp.second;
			cab[temp.second][temp.first] = 1;
		}

		for (j = 0; j < N; j++)
		{
			for (u = 0; u < M; u++)
			{
				if (cab[j][u] && !visited[j][u])
				{
					s.push(make_pair(j, u));

					while (!s.empty())
					{
						int cur_x = s.top().first;
						int cur_y = s.top().second;
						s.pop();


						for (auto d : directed)
						{
							int n_x = cur_x + d.first;
							int n_y = cur_y + d.second;

							if (n_x >= 0 && n_y >= 0 && n_x < N && n_y < M &&
								cab[n_x][n_y] && !visited[n_x][n_y])
							{
								visited[n_x][n_y] = 1;
								s.push(make_pair(n_x, n_y));
							}
						}

					}
					sum++;
				}
			}
		}
		cout << sum << "\n";
	}

	return 0;
}
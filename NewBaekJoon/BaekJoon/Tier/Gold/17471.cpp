#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

bool flag = false;
vector<int>a;
vector<vector<int>>chain;
vector<int>map;
vector<bool>visited(11, false);

int mini = 999999999;
int N;

bool check(const vector<int>& v)
{
	bool flag = false;
	visited.assign(11, false);
	queue<int>q;
	q.push(v[0]);
	int cnt = 0;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		visited[cur] = true;
		cnt++;
		for (int i = 0; i < chain[cur].size(); i++)
		{
			int next = chain[cur][i];

			if (find(v.begin(), v.end(), next) != v.end()) // 존재한다면
			{
				if (visited[next] == false)
				{
					q.push(next);
					visited[next] = true;
				}
			}
		}

	}

	if (cnt == v.size())
		return true;
	return false;
}

void solve()
{
	vector<int> other;

	for (int i = 0; i < N; i++)
	{
		if (find(a.begin(), a.end(), i) == a.end()) // i가 a내에 존재하지 않으면
			other.push_back(i); // i를 other 그룹에 추가.
	}

	if (check(a) && check(other)) // other과 a가 각각 이어져있으면 other 그룹과 a 그룹의 인구 합계 구하고, 최소.
	{
		flag = true; // 한번이라도 이어져있었다면, flag를 true로.
		int a_sum = 0;
		int other_sum = 0;

		for (auto i : a)
			a_sum += map[i];
		for (auto i : other)
			other_sum += map[i];

		int diff = abs(a_sum - other_sum);

		mini = min(diff, mini);
	}
}


void combi(int start)
{
	if (start != -1) solve();
	if (start == N - 2) return;

	for (int i = start + 1; i < N; i++)
	{
		a.push_back(i);
		combi(i);
		a.pop_back();
	}
}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	map.assign(N, 0);
	chain.assign(N, vector<int>(N));

	for (int i = 0; i < N; i++)
		cin >> map[i];

	for (int i = 0; i < N; i++)
	{
		int num, temp;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> temp;
			chain[i][j] = temp - 1;
		}
	}

	combi(-1);
	if (!flag)
		cout << -1;
	else
		cout << mini;
	return 0;
}
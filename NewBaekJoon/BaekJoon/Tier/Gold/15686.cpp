#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int minimum = 999999999;
int N, M;
int i, j;

void combi(int start, vector<int> b) {
	if (b.size() == M) {
		int sum = 0;
		for (auto h : house)
		{
			int mini = 999999999;
			for (auto i : b)
			{
				int dist = abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second);
				mini = min(mini, dist);
			}
			sum += mini;
		}
		minimum = min(sum, minimum);
	};

	for (int i = start + 1; i < chicken.size(); i++) {
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	};
	return;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;

	vector<int>b;
	vector<vector<int>>city(N + 1, vector<int>(N + 1, 0));


	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 1)
				house.push_back(make_pair(i, j));
			else if (city[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}

	combi(-1, b);

	cout << minimum;
	return 0;
}
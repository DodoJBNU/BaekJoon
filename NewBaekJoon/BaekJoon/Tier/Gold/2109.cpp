#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool visited[10001];

bool compare(pair<int, int>a, pair<int, int> b)
{
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, i, j;
	cin >> n;

	vector<pair<int, int>> uni(n);

	for (i = 0; i < n; i++)
		cin >> uni[i].first >> uni[i].second; // first: price, second: day

	sort(uni.begin(), uni.end(), compare);

	int sum = 0;

	for (i = 0; i < n; i++)
	{
		for (j = uni[i].second; j >= 1; j--)
		{
			if (visited[j] == false)
			{
				visited[j] = true;
				sum += uni[i].first;
				break;
			}
		}
	}

	cout << sum;
	return 0;
}
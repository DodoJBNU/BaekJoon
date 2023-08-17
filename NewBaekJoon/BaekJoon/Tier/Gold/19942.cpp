#include<iostream>
#include<vector>
using namespace std;

const int MAX = 999999999;
int N;
vector<int> list;
vector<vector<int>>res(1, vector<int>(5,0));
vector<vector<int>>minimum(1, vector<int>(4, 0));

void Backtracking(int start, vector<int> b, vector<vector<int>>sum, const vector<vector<int>> &n)
{
	if (start != -1)
	{
		for (int i = 0; i <= 4; i++)
			sum[0][i] += n[start][i];

		bool flag = true;

		for (int i = 0; i < 4; i++)
		{
			if (sum[0][i] < minimum[0][i])
			{
				flag = false; // 하나라도 최소치보다 작다면 false,
				break;
			}
		}

		if (flag) // 최소치넘긴다면,
		{
			if (list.size() == 0)
			{
				res = sum;
				list = b;
			}
			else
			{
				if (sum[0][4] < res[0][4])
				{
					res = sum;
					list = b;
				}
				else if (sum[0][4] == res[0][4] && b < list)
				{
					res = sum;
					list = b;
				}
			}
			return;
		}
	}
	for (int i = start + 1; i < N; i++)
	{
		b.push_back(i);
		Backtracking(i, b, sum, n);
		b.pop_back();
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int i, j;
	cin >> N;
	for (i = 0; i < 4; i++)
		cin >> minimum[0][i];
	

	vector<vector<int>>n(N, vector<int>(5, 0));
	vector<vector<int>>sum(1, vector<int>(5, 0));
	vector<int> b;
	res[0][4] = MAX; // cost max

	for (i = 0; i < N; i++)
		for (j = 0; j <= 4; j++)
			cin >> n[i][j];

	Backtracking(-1, b, sum ,n);

	if (res[0][4] != MAX)
	{
		cout << res[0][4] << "\n";
		for (auto l : list) {
			cout << l + 1 << " ";
		}
	}
	else
		cout << -1;

	return 0;
}
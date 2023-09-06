#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int> input;

void combi(int start, vector<int>b)
{
	if (b.size() == M)
	{
		for (auto k : b)
		{
			cout << k << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start + 1; i < input.size(); i++)
	{
		bool flag = true;
		
		for (int j = 0; j < b.size(); j++)
		{
			if (b[j] == input[i])
			{
				flag = false;
				break;
			}
		}
		
		if (flag)
		{
			b.push_back(input[i]);
			combi(start, b);
			b.pop_back();
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

	for (int i = 0; i < N; i++)
		cin >> input[i];

	sort(input.begin(), input.end(), less<>());
	vector<int>b;
	combi(-1, b);
	return 0;
}
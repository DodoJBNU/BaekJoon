#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;

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
	for (int i = start+1; i <= N; i++)
	{
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<int>b;
	combi(0, b);
	return 0;
}
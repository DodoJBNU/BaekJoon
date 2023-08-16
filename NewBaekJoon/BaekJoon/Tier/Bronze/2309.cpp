#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N = 7;

bool flag = false;
vector<int> dwarf(9, 0);
void combi(int start, vector<int> b)
{
	if (b.size() == N)
	{
		int sum = 0;
		for (int i = 0; i < b.size(); i++)
			sum += dwarf[b[i]];
		
		if (sum == 100 && !flag)
		{
			flag = true;
			vector<int> res;
			for (int i = 0; i < b.size(); i++)
			{
				res.push_back(dwarf[b[i]]);
			}
			sort(res.begin(), res.end());

			for (auto result : res)
				cout << result << "\n";
			
		}
	}

	for (int i = start+1; i < dwarf.size(); i++)
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

	vector<int> b;
	for (int i = 0; i < 9; i++)
		cin >> dwarf[i];

	combi(-1, b);
	return 0;
}
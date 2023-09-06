#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,i;
	cin >> N;
	vector<string> word(N);

	for (i = 0; i < N; i++)
		cin >> word[i];
	sort(word.begin(), word.end(), cmp);

	string check = word[0];

	int k = 1;
	while (k < word.size())
	{
		if (check == word[k])
		{
			 word.erase(word.begin() + k);
			 continue;
		}
		else 
		{
			check = word[k];
			k++;
		}
	}

	for (i = 0; i < word.size(); i++)
		cout << word[i] << "\n";
	return 0;
}
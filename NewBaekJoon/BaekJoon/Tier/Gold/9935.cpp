#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/* substr을 사용한 버전.
	string s, t, ret = "";

	cin >> s >> t;

	for (char c : s)
	{
		ret += c;
		if (ret.size() >= t.size() && ret.substr(ret.size() - t.size(), t.size()) == t)
		{
			ret.erase(ret.begin()  + ret.size() - t.size(), ret.end());
		}
	}
	if (!ret.empty())
		cout << ret;
	else
		cout << "FRULA";

	*/
	// 아래는 stack을 사용한 버전

	string s, bomb;
	stack<char> st;
	string check = "";

	cin >> s >> bomb;

	int i,j;

	for (i = 0; i < s.size(); i++)
	{
		st.push(s[i]);

		if (st.size() >= bomb.size() && st.top() == bomb[bomb.size() - 1])
		{
			check = "";
			for (j = 0; j < bomb.size(); j++)
			{
				check += st.top(); st.pop();
			}
			reverse(check.begin(), check.end());


			if (check != bomb)
			{
				for (j = 0; j < check.size(); j++)
				{
					st.push(check[j]);
				}
			}
		}

	}

	string res = "";

	if (!st.empty())
	{
		while (!st.empty()) {
			res += st.top();
			st.pop();
		}
		reverse(res.begin(), res.end());

		cout << res;
	}
	else
		cout << "FRULA";
	return 0;
}
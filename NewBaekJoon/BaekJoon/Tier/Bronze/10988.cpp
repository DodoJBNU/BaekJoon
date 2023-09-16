#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;

	int end = input.size() - 1;
	bool flag = true;
	for (int i = 0; i<input.size() / 2; i++)
	{
		if (input[i] != input[end - i])
		{
			flag = false;
			break;
		}
	}
	if (!flag)
		cout << 0;
	else
		cout << 1; 
	return 0;
}
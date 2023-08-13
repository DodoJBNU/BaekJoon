#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	int sum = 0, count = 0;
	cin >> n >> k;
	vector<int>coin(n);

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	int i = coin.size() - 1; // 뒤에서부터 접근
	while (i >= 0)
	{
		if (sum + coin[i] == k)
		{
			count++;
			break;
		}
		else if (sum + coin[i] < k)
		{
			count++;
			sum += coin[i];
		}
		else if(sum+coin[i]>k)
		{
			i--;
		}
	}

	cout << count;
	return 0;
}
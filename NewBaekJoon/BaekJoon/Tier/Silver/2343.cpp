#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int l, mid, r;
	int i;
	cin >> n >> m;

	l = 0; r = 0;

	vector<int> lec(n);
	vector<int> idx(m, n-1);
	vector<int> blue(m, 0);
	for (i = 0; i < n; i++)
	{
		cin >> lec[i];
		r += lec[i];
		if (lec[i] > l) l = lec[i];
	}



	while (l <= r)
	{
		int cnt = 0;
		int tempSum = 0;
		mid = (l + r) / 2;

		for (i = 0; i < n; i++)
		{
			if (tempSum + lec[i] > mid) {
				tempSum = 0;
				cnt++;
			}
			tempSum += lec[i];
		}
		cnt++;

		if (cnt <= m) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}


	}
	cout << l;
	return 0;
}
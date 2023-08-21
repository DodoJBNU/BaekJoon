#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	vector<int> start(3);
	vector<int> end(3);
	vector<int> car;
	int sum = 0;
	cin >> a >> b >> c;
	
	for (int i = 0; i < 3; i++)
		cin >> start[i] >> end[i];

	sort(start.begin(), start.end());
	sort(end.begin(), end.end());

	car.push_back(1);
	for (int i = start[0]; i <= end[2]; i++)
	{
		if (start[1] == i)
			car.push_back(1);
		if (start[2] == i)
			car.push_back(1);
		if (end[0] == i)
			car.pop_back();
		if (end[1] == i)
			car.pop_back();
		if (end[2] == i)
			car.pop_back();

		if (car.size() == 1)
		{
			sum += a;
		}
		else if (car.size() == 2)
		{
			sum += 2 * b;
		}
		else if (car.size() == 3)
		{
			sum += 3 * c;
		}
	}

	cout << sum;
	return 0;
}
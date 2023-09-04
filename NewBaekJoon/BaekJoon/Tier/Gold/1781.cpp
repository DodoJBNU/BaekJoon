#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Ramen
{
public:
	int dead;
	int vol;
	Ramen(int dead, int vol) : dead(dead), vol(vol) {}
	Ramen() : dead(0), vol(0) {}
};

int N;
vector<Ramen> R;


class cmp {
public:
	bool operator()(const Ramen &r1, const Ramen &r2) const
	{
		if (r1.dead == r2.dead) return r1.vol > r2.vol;
		return r1.dead < r2.dead;
	}
};
bool cmp(Ramen r1, Ramen r2)
{
	if (r1.dead == r2.dead) return r1.vol > r2.vol;
	return r1.dead < r2.dead;
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;
	int dead, vol;

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> dead >> vol;
		R.push_back(Ramen(dead, vol));
	}

	sort(R.begin(), R.end(), cmp);
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++)
	{
		if (pq.size() < R[i].dead)
		{
			pq.push(R[i].vol);
		}
		else
		{
			if (pq.top() < R[i].vol)
			{
				pq.pop();
				pq.push(R[i].vol);
			}
		}
	}

	
	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
	return 0;
}
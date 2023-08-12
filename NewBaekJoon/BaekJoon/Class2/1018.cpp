#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int CheckBoardMinimum(const vector<vector<char>> &InputBoard, int n, int m)
{
	int i, j, u, v;
	// 보드 세팅 
	const char WbBoard[8][8] =
	{
		{'W', 'B','W', 'B','W', 'B','W', 'B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'},
		{'W', 'B','W', 'B','W', 'B','W', 'B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'},
		{'W', 'B','W', 'B','W', 'B','W', 'B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'},
		{'W', 'B','W', 'B','W', 'B','W', 'B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'}
	};

	const char BwBoard[8][8] =
	{
		{'B', 'W','B', 'W','B', 'W','B', 'W'},
		{'W', 'B','W', 'B','W', 'B','W', 'B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'},
		{'W', 'B','W', 'B','W', 'B','W', 'B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'},
		{'W', 'B','W', 'B','W', 'B','W', 'B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'},
		{'W', 'B','W', 'B','W', 'B','W', 'B'}
	};
	//

	int Wb_count = 0;
	int Bw_count = 0;
	int minimum = 2501;


	for (i = 0; i <= n-8; i++)
	{
		for (j = 0; j <= m - 8; j++)
		{
			for (u = 0; u < 8; u++)
			{
				for (v = 0; v < 8; v++)
				{
					if (WbBoard[u][v] != InputBoard[i + u][j + v]) Wb_count++;
					if (BwBoard[u][v] != InputBoard[i + u][j + v]) Bw_count++;
				}
			}
			minimum = min({ Wb_count, Bw_count, minimum });
			Wb_count = 0;
			Bw_count = 0;
		}
	}

	return minimum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m;
	int i, j;
	cin >> n >> m;
	vector<vector<char>> InputBoard(n, vector<char>(m));

	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> InputBoard[i][j];
		}
	}

	int min = CheckBoardMinimum(InputBoard, n, m);

	cout << min;
	
	return 0;
}
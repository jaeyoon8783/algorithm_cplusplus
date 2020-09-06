﻿#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
	int right[501][501];
	int down[501][501];

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			right[i][j] = 0;
			down[i][j] = 0;
		}
	}

	for (int x = 1; x <= m; x++) {
		for (int y = 1; y <= n; y++) {
			int type = city_map[x - 1][y - 1];
			if ((x == 1) && (y == 1)) {
				right[x][y] = 1;
				down[x][y] = 1;
			}
			else if (type == 0) {
				right[x][y] = (right[x][y - 1] + down[x - 1][y]) % MOD;
				down[x][y] = (right[x][y - 1] + down[x - 1][y]) % MOD;
			}
			else if (type == 1) {
				right[x][y] = 0;
				down[x][y] = 0;
			}
			else if (type == 2) {
				right[x][y] = right[x][y - 1];
				down[x][y] = down[x - 1][y];
			}
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << right[i][j] << '/' << down[i][j] << ' ';
		}
		cout << '\n';
	}

	return right[m][n];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m = 4;
	int n = 4;


	//vector<vector<int>> cm = { {0,2,0,0,0,2}, {0,0,2,0,1,0}, {1,0,0,2,2,0} };
	vector<vector<int>> cm = { {0,0,0,0}, {0,0,0,0}, {0,0,0,2}, {0,0,2,0} };
	//vector<vector<int>> cm = { {0}, {0}, {0}, {0} };



	cout << solution(m, n, cm);


}

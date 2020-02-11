#include<iostream>
#include<vector>
#define MAX_SIZE 300+1
using namespace std;

vector< vector<int> > v;

int cache[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE] = { 0 };

int fun(int i, int j, int x, int y, int M)
{
	//int& ret = cache[i][j][x][y];

	//if (ret != 0)
	//	return ret;
	if (i > x)
		return 0;
	if (j == M)
		return/*ret = */v[i][j] + fun(i + 1, 0, x, y, M);
	if (i != x)
		return/* ret = */v[i][j] + fun(i, j + 1, x, y, M);
	else
		return/* ret = */v[i][j] + fun(i, j + 1, x, y, y);
}

int main(void)
{
	int N, M;
	int k;
	int i, j, x, y;
	int element;

	cin >> N >> M;
	vector<int> vs;
	vs.assign(M, 0);
	v.assign(N, vs);

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			cin >> v[row][col];
		}
	}

	cin >> k;

	while (k--)
	{
		cin >> i >> j >> x >> y;
		cout << fun(i-1, j-1, x-1, y-1, M-1);
	}

	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct connectInfo {
	bool bIsConnected;
	int len;
}ConnectInfos;
int dir[4][2]
{
	{-1,0},
	{0,1},
	{1,0},
	{0,-1},
};

ConnectInfos set(int dIdx, int yPos, int xPos, vector<vector<int>>& cells)
{
	ConnectInfos aInfo;

	aInfo.bIsConnected = false;
	aInfo.len = 0;

	int y = yPos + dir[dIdx][0];
	int x = xPos + dir[dIdx][1];

	while (y >= 0 && y < cells.size() && x >= 0 && x < cells.size() && !cells[y][x])
	{

		if (y == 0 || y == cells.size() - 1 || x == 0 || x == cells.size() - 1)
		{
			aInfo.bIsConnected = true;
		}
		y += dir[dIdx][0];
		x += dir[dIdx][1];
	}
	if (!aInfo.bIsConnected)
	{
		return aInfo;
	}
	else
	{
		aInfo.bIsConnected = true;
		
		y = yPos + dir[dIdx][0];
		x = xPos + dir[dIdx][1];

		while (y >= 0 && y < cells.size() && x >= 0 && x < cells.size() && !cells[y][x])
		{
			cells[y][x] = 2;
			aInfo.len++;
			y += dir[dIdx][0];
			x += dir[dIdx][1];
		}

		return aInfo;
	}
}

int getMaxConnectedLenRecursive(vector<vector<int>>& cells)
{
	bool state = true;
	int xPos;
	int yPos;
	//종료조건
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells.size(); j++)
		{
			if (cells[i][j] == 1)
			{
				state = false;
				yPos = i;
				xPos = j;
				break;
			}
		}
		if (!state)
		{
			break;
		}
	}

	if (state)
	{
		return 0;
	}
	for (int dIdx = 0; dIdx < 4; dIdx++)
	{
		//연결
		ConnectInfos aInfo = set(dIdx, yPos, xPos, cells);
		//재귀
		getMaxConnectedLenRecursive(cells);
		//비교

		//해제
	}
	return getMinLen(yPos, xPos, cells) + getMaxConnectedLenRecursive(cells);
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int size;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> size;
		int sum = 0;
		vector<int> vs(size, 0);
		vector<vector<int>> MexinosCells(size, vs);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cin >> MexinosCells[i][j];
			}
		}
		sum = getMaxConnectedLenRecursive(MexinosCells);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << MexinosCells[i][j] << " ";
			}
			cout << endl;
		}
		cout << "#" << test_case << " " << sum << endl;
	}
	return 0;
}
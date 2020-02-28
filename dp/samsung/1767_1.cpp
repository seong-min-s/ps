#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dir[4][2]
{
	{-1,0},
	{0,1},
	{1,0},
	{0,-1},
};

int getMinLen(int yPos,int xPos, vector<vector<int>>& cells)
{
	int optimumDir= -1;
	int minLen=1234567;
	//4개의 방향을 돌면서 전원부가 연결되었을 때의 최소길이를 구한다. 전원부가 연결되지 않으면 최적 방향은 -1이다.
	for (int dIdx = 0; dIdx < 4; dIdx++)
	{
		int len = 0;
		   
		int y=yPos+ dir[dIdx][0];
		int x=xPos+ dir[dIdx][1];

		while (x >= 0 && x < cells.size() && y >= 0 && y < cells.size() && !cells[y][x])
		{
			len++;
			y += dir[dIdx][0];
			x += dir[dIdx][1];
		}
		
		if (x < 0 || x == cells.size() || y < 0 || y == cells.size())//전원부연결되었을 때
		{
			if (minLen > len)
			{
				optimumDir = dIdx;
				minLen = len;
			}
		}
	}
	cells[yPos][xPos] = 3;//최적화끝난 셀 표시
	if (optimumDir == -1)
	{
		return 0;
	}
	else//최적방향이 정해졌을 경우 길이를 연결해준다. 코어와 구분하기 위해서 값 2를 넣어준다.
	{
		yPos += dir[optimumDir][0];
		xPos += dir[optimumDir][1];

		while (xPos >= 0 && xPos < cells.size() && yPos >= 0 && yPos < cells.size())
		{
			cells[yPos][xPos] = 2;
			yPos += dir[optimumDir][0];
			xPos += dir[optimumDir][1];
		}
	}
	return minLen;
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
	//연결
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
		vector<vector<int>> MexinosCells(size,vs);
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
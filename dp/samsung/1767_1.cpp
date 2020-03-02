#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> result;
typedef struct connectInfo {
	int powerCount;
	int len;
}ConnectInfo;
int dir[4][2]
{
	{-1,0},
	{0,1},
	{1,0},
	{0,-1},
};

ConnectInfo set(int dIdx, int yPos, int xPos, vector<vector<int>>& cells)
{
	ConnectInfo result;
	bool bFlagConnected = false;
	int len = 0;
	int y = yPos;
	int x = xPos;

	cells[y][x] = 3;//방문표시

	//전원부에 인접한 경우
	if (dIdx == 0 && yPos == 0)
	{
		result.powerCount = 1;
		result.len = 0;
		return result;
	}
	else if (dIdx == 1 && xPos == cells.size() - 1)
	{
		result.powerCount = 1;
		result.len = 0;
		return result;
	}
	else if (dIdx == 2 && yPos == cells.size() - 1)
	{
		result.powerCount = 1;
		result.len = 0;
		return result;
	}
	else if (dIdx == 3 && xPos == 0)
	{
		result.powerCount = 1;
		result.len = 0;
		return result;
	}
	else if (dIdx == 4)
	{
		result.powerCount = 0;
		result.len = 0;
		return result;
	}

	//특정 방향의 전원부까지 연결을 할 수 있는가?
	y = yPos + dir[dIdx][0];
	x = xPos + dir[dIdx][1];

	while (y >= 0 && y < cells.size() && x >= 0 && x < cells.size())
	{
		if (cells[y][x] == 1 || cells[y][x] == 2 || cells[y][x] == 3 || cells[y][x] == -1) //장애물을 만났을 경우
		{
			break;
		}
		if (y == 0 || y == cells.size() - 1 || x == 0 || x == cells.size() - 1) //전원부 인접에 도달했을 경우
		{
			bFlagConnected = true;
		}
		y += dir[dIdx][0];
		x += dir[dIdx][1];
	}

	if (!bFlagConnected)
	{
		result.powerCount = 0;
		result.len = 0;
		return result;
	}
	else
	{
		y = yPos + dir[dIdx][0];
		x = xPos + dir[dIdx][1];

		while (y >= 0 && y < cells.size() && x >= 0 && x < cells.size() && !cells[y][x])
		{
			cells[y][x] = 2;//길이표시
			y += dir[dIdx][0];
			x += dir[dIdx][1];
			len++;
		}
		result.powerCount = 1;
		result.len = len;
		return result;
	}
}

void unset(int dIdx, int yPos, int xPos, vector<vector<int>> cells, vector<vector<int>> restore)
{
	cells = restore;
}

ConnectInfo getMaxConnectedLenRecursive(vector<vector<int>>& cells, int power, int len)
{
	ConnectInfo info = { 0,0 };
	vector<vector<int>> restoreV = cells;
	bool state = true;
	int xPos;
	int yPos;

	//방문여부
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

	//모든 노드를 방문했다면 종료
	if (state)
	{
		ConnectInfo result;
		result.powerCount = power;
		result.len = len;

		return result;
	}

	int powerMax = -1;
	int lenMin = 1000;

	for (int dIdx = 0; dIdx < 5; dIdx++)
	{
		//연결
		ConnectInfo afterSetInfo = set(dIdx, yPos, xPos, cells);

		//나머지 셀에서 연결정보를 탐색하고, 비교한다.
		info = getMaxConnectedLenRecursive(cells, power + afterSetInfo.powerCount, len + afterSetInfo.len);
		if (info.powerCount > powerMax && info.len < lenMin)
		{
			powerMax = info.powerCount;
			lenMin = info.len;
		}
		//해제
		unset(dIdx, yPos, xPos, cells, restoreV);
	}
	info.powerCount = powerMax;
	info.len = lenMin;
	return info;
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
		ConnectInfo ret = getMaxConnectedLenRecursive(MexinosCells, 0, 0);

		cout << "#" << test_case << " "<<ret.powerCount << " " << ret.len << endl;

	}
	return 0;
}
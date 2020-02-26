#include<iostream>
#include<vector>

using namespace std;

int coverType[4][3][2] = {
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{0,1},{1,0}},
	{{0,0},{1,-1},{1,0}}
};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; ++i)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
		{
			ok = false;
		}
		else if ((board[ny][nx] += delta) > 1)
		{
			ok = false;
		}
	}
	return ok;
}
int coverBoard(vector<vector<int>>& board)
{
	int startYpos = -1;
	int startXpos = -1;
	int ret = 0;
	for (int yPos = 0; yPos < board.size(); ++yPos)
	{
		for (int xPos = 0; xPos < board[yPos].size(); ++xPos)
		{
			if (board[yPos][xPos] == 0)
			{
				startYpos = yPos;
				startXpos = xPos;
				break;
			}
		}
		if (startYpos != -1)
		{
			break;
		}
	}
	if (startYpos == -1)
	{
		return 1;
	}

	for (int type = 0; type < 4; ++type)
	{
		if (set(board, startYpos, startXpos, type, 1))
		{
			ret += coverBoard(board);
		}
		set(board, startYpos, startXpos, type, -1);
	}
	return ret;
}

int main()
{

	/*int board1[3][7] =
	{
		{1,0,0,0,0,0,1},
		{1,0,0,0,0,0,1},
		{1,1,0,0,0,1,1}
	};*/
	/*vector<vector<int>> v;
	vector<int> vs;
	for (int i = 0; i < 3; i++)
	{
		vs.assign(board1[i], board1[i] + 7);
		v.push_back(vs);
	}*/
	vector<vector<int>> v2;
	vector<int> vs2;

	int board2[8][10] =
	{
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};
	for (int i = 0; i < 8; i++)
	{
		vs2.assign(board2[i], board2[i] + 10);
		v2.push_back(vs2);
	}	
	cout << coverBoard(v2);
	return 0;
}
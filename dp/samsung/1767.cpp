#include<iostream>
#include<queue>
#include<algorithm>
#define MEXINOS_SIZE 12
using namespace std;

int Mexinos[MEXINOS_SIZE][MEXINOS_SIZE];
int xMove[4] = { 1,-1,0,0 };
int yMove[4] = { 0,0,1,-1 };
enum eDir
{
	EAST, WEST, SOUTH, NORTH, DIR_END
};
typedef struct MexinosCell {
	int yPos;
	int xPos;
}Cell;

typedef struct Log {
	int powerCount;
	int len;
}Log;

vector<Log> logMemory;


void GetLenFromPowerToMexinosRecursive(int powerCnt, int len, queue<Cell>& q, int(*isVisited)[MEXINOS_SIZE])
{
	//종료조건
	if (q.empty())
	{
		Log logTmp;
		logTmp.powerCount = powerCnt;
		logTmp.len = len;
		logMemory.emplace_back(logTmp);
		return;
	}
	//현재 위치 방문
	Cell c = q.front();
	q.pop();
	isVisited[c.yPos][c.xPos] = 1;
	int dir;
	int count = 0;

	//4가지 방향으로 가기
	for (int dir = EAST; dir < DIR_END; dir++)
	{
		int x=0, y=0;
		switch (dir)
		{
		case eDir::EAST:
			x = c.xPos + xMove[0];
			y = c.yPos + yMove[0];
			count = 0;
			while (isVisited[y][x] != 1)
			{
				isVisited[y][x] = 1;
				count++;
				if (x == MEXINOS_SIZE)
				{
					powerCnt++;
					len += count;
				}
				x++;
			}
			GetLenFromPowerToMexinosRecursive(powerCnt, len, q, isVisited);
			break;

		case eDir::WEST:
			x = c.xPos + xMove[1];
			y = c.yPos + yMove[1];
			count = 0;
			while (isVisited[y][x] != 1)
			{
				isVisited[y][x] = 1;
				count++;
				if (x == 0)
				{
					powerCnt++;
					len += count;
				}
				x--;
			}
			GetLenFromPowerToMexinosRecursive(powerCnt, len, q, isVisited);
			break;

		case eDir::SOUTH:
			x = c.xPos + xMove[1];
			y = c.yPos + yMove[1];
			count = 0;
			while (isVisited[y][x] != 1)
			{
				isVisited[y][x] = 1;
				count++;
				if (y == MEXINOS_SIZE)
				{
					powerCnt++;
					len += count;
				}
				y++;
			}
			GetLenFromPowerToMexinosRecursive(powerCnt, len, q, isVisited);
			break;
		case eDir::NORTH:
			x = c.xPos + xMove[1];
			y = c.yPos + yMove[1];
			count = 0;
			while (isVisited[y][x] != 1)
			{
				isVisited[y][x] = 1;
				count++;
				if (y == 0)
				{
					powerCnt++;
					len += count;
				}
				y--;
			}
			GetLenFromPowerToMexinosRecursive(powerCnt, len, q, isVisited);
			break;
		default:
			break;
		}
	}


}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int size;
	int sum;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int isVisited[MEXINOS_SIZE][MEXINOS_SIZE] = { 0 };
		sum = 0;
		cin >> size;
		queue<Cell> q;
		//input
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				cin >> Mexinos[y][x];
				if (Mexinos[y][x] == 1)
				{
					Cell cell;
					cell.yPos = y;
					cell.xPos = x;
					q.push(cell);
				}
			}
		}
		//calculate
		GetLenFromPowerToMexinosRecursive(0, sum, q, isVisited);

		//filtering
		int MaxPower = -1;
		int MinLen = 500;

		for (int i = 0; i < logMemory.size(); i++)
		{
			if (logMemory[i].powerCount > MaxPower)
			{
				MaxPower = logMemory[i].powerCount;
			}
		}
		for (int i = 0; i < logMemory.size(); i++)
		{
			if (logMemory[i].powerCount == MaxPower)
			{
				if (MinLen > logMemory[i].len)
				{
					MinLen = logMemory[i].len;
				}
			}
		}

		cout << "#" << test_case << " " << MinLen << endl;
	}
	return 0;
}
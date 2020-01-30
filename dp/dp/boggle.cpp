#include <iostream>
#include <string>

using namespace std;

int dirX[8] = { 1, 1, 0, -1, -1, -1, -1,  0 };
int dirY[8] = { 0, 1, 1,  1,  0, -1, -1, -1 };

char board[5][5];

bool inRange(int y, int x)
{
	if (y < 0 || x < 0 || y > 4 || x > 4)
	{
		return false;
	}
	return true;
}

bool FindWordRecursive(int y, int x, const string& word)
{
	if (!inRange(y, x))
	{
		return false;
	}
	if (board[y][x] != word[0])
	{
		return false;
	}
	if (word.size() == 1)
	{
		return true;
	}

	for (int direction = 0; direction < 8; ++direction)
	{
		int nextY = y + dirY[direction], nextX = x + dirX[direction];

		if (FindWordRecursive(nextY, nextX, word.substr(1)))
		{
			return true;
		}
	}
	return false;
}

int main(void)
{
	int testCase = 0;
	int num = 0;
	char cstr[] = "hello";
	string word = "PREETY";
	bool isWord = false;

	FILE* fp = fopen("test.txt", "r");
	//fscanf_s(fp, board);
	
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		//보드판입력받기
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				cin >> board[y][x];
			}
		}
		//cin >> num;
		num = 1;
		for (int i = 0; i < num; i++)
		{
			//검색할단어
			//cin >> word;
			//word = "PREETY";
			isWord = false;
			for (int y = 0; y < 5; y++)
			{
				for (int x = 0; x < 5; x++)
				{
					isWord = FindWordRecursive(y, x, word);
					if (isWord)
						break;
				}
				if (isWord)
					break;
			}
			//결과 출력
			cout << word << " " << isWord << endl;
		}
	}
	return 0;
}
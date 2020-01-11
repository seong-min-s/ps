#include <iostream>
#include <string>

using namespace std;

int dirX[8] = { 1, 1, 0, -1, -1, -1, -1,  0 };

int diry[8] = { 0, 1, 1,  1,  0, -1, -1, -1 };

bool FindWordRecursive(int index, int lastIndex int x, int y)
{
	bool isWord;

	if (
		if (index > lastIndex)
		{
			return true;
		}
		else
		{
			index++;
				for (int i = 0; i < 8; i++)
				{
					isWord = FindWordRecursive(index,

				}

		}

}
int main(void)
{

	int testCase = 0;
	char word[10];
	char board[5][5];
	int lastIndex = 0;
	bool isWord = false;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		//보드판
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				cin >> board[y][x];
			}
		}

		//단어
		cin >> word;

		//lastIndex = word.l

		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				if (word[0] == board[y][x])
				{
					isWord = FindWordRecursive(0, y, x);
				}

				if (isWord == true)
				{
					break;
				}
			}
		}
		//결과 출력
		cout << word << " " << isWord << endl;

	}


	return 0;
}
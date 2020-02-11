#include<iostream>
using namespace std;

int Mexinos[13][13];
int xPos[4] = { 1,0,-1,0 };
int yPos[4] = { 0,1,0,-1 };

int getLenFromPowerToMexinosRecursive(int y, int x, int d, int size)
{
	if (y == size - 1)
		return 0;
	if (y == 0)
		return 0;
	if (x == size - 1)
		return 0;
	if (x == 0)
		return 0;
	if (Mexinos[y + yPos[d]][x + xPos[d]] == 1)
		return 13;

	return 1 + getLenFromPowerToMexinosRecursive(y + yPos[d], x + xPos[d], d, size);
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
		//input
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				cin >> Mexinos[y][x];
			}
		}
		//calculate
		for (int y = 0; y < size; y++)
		{
			int result = 0;
			for (int x = 0; x < size; x++)
			{
				if (Mexinos[y][x] == 1)
				{
					int min = 13;
					for (int dir = 0; dir < 4; dir++)
					{
						result = getLenFromPowerToMexinosRecursive(y, x, dir, size);
						if (min >= result)
						{
							min = result;
						}
					}
					sum += min;
				}
			}
		}
		cout << "#" << test_case << " " << sum << endl;
	}
	return 0;
}
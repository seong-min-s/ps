#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int codes[50][100] = { 0, };
int main(void)
{
	int testCase;
	int rowLen;
	int colLen;

	cin >> testCase;

	for (int i = 1; i <= testCase; i++)
	{
		cin >> rowLen >> colLen;
		int code = 0;
		int digit;
		for (int y = 0; y < rowLen; y++)
		{
			for (int x = 0; x < colLen; x++)
			{
				cin >> codes[y][x];
			}
		}
		int codeLastIdx = -1;
		int codeRow = 0;
		int evenSum = 0;
		int oddSum = 0;
		int sum = 0;
		for (int y = 0; y < rowLen; ++y)
		{
			for (int x = colLen; x >= 0; --x)
			{
				if (codes[y][x] == 1)
				{
					codeLastIdx = x;
					codeRow = y;
					break;
				}
			}
			if (codeLastIdx)
			{
				break;
			}
		}

		evenSum = 3*(codes[codeRow][0] + codes[codeRow][2] + codes[codeRow][4] + codes[codeRow][6]);
		oddSum = codes[codeRow][1] + codes[codeRow][3] + codes[codeRow][5];
		sum = evenSum + oddSum;
		code = 10 - sum % 10;

		if (code != codes[codeRow][7])
		{
			code = 0;
		}

		cout << "# " << i << " " << code << endl;
	}
}
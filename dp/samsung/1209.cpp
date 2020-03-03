#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//cin >> T;
	vector<int> vs(100, 0);
	vector<vector<int>> v(100, vs);
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				cin >> v[i][j];
			}
		}

		int max_value = -1;	
		int sum;
		for (int i = 0; i < 100; i++)
		{
			sum = 0;
			//오른쪽으로
			for (int j = 0; j < 100; j++)
			{
				sum += v[i][j];
			}
			max_value = max(sum, max_value);
			//아래쪽으로
			sum = 0;
			for (int j = 0; j < 100; j++)
			{
				sum += v[j][i];
			}
			max_value = max(sum, max_value);
		}

		//왼오 아래 대각
		sum = 0;
		for (int i = 0; i < 100; i++)
		{
			sum += v[i][i];
		}
		max_value = max(sum, max_value);


		//오른쪽에서 왼쪽 아래로 대각선
		sum = 0;
		for (int i = 0; i < 100; i++)
		{
			sum += v[0 + i][(99 - i)];
		}
		max_value = max(sum, max_value);

		cout << "#" << test_case << " " << max_value << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
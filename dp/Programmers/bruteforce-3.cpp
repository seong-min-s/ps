#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> cases;
void getWays(int num, vector<vector<int>> baseball)
{
	int a[3];
	int subject = num;
	if (num > 987)
	{
		return;
	}

	bool willBe = true;

	for (int i = 0; i < 3; i++)
	{
		if (!(a[i] = subject % 10))
		{
			willBe = false;
			break;
		}
		subject = subject / 10;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (a[i] == a[j])
			{
				willBe = false;
				break;
			}
		}
	}
	if (willBe)
	{
		for (vector<int> cmd : baseball)
		{
			int strikeCount = 0;
			int ballCount = 0;
			
			for (int i = 0; i < 3; i++)
			{
				int number = cmd[0];
				for (int j = 0; j < 3; j++)
				{
					if (a[i] == number % 10)
					{
						if (i == j)
						{
							strikeCount++;
						}
						else
						{
							ballCount++;
						}
					}
					number /= 10;
				}
			}
			if (strikeCount != cmd[1] || ballCount != cmd[2])
			{
				willBe = false;
				break;
			}
		}

		if (willBe == true)
		{
			cases.push_back(num);
		}
	}
	
	getWays(num + 1, baseball);
}
int solution(vector<vector<int>> baseball) {
	int answer = 0;
	getWays(324, baseball);

	answer = cases.size();
	return answer;
}
int main()
{
	vector<vector<int>> v = { {123, 1, 1},{356, 1, 0},{327, 2, 0},{489, 0, 1} };
	cout << solution(v);
	return 0;
}
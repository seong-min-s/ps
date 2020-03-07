
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct pos {
	int y;
	int x;
}Pos;

int dfs(vector<int>& isVisited, vector<Pos>& customers, Pos& curPos, Pos& home, int len)
{
	int flag = -1;
	for (int i = 0; i < isVisited.size(); i++)
	{
		if (isVisited[i] == 0)
		{
			flag = i;
			break;
		}
	}

	if (!flag)
	{
		len = len + abs(curPos.x - home.x) + abs(curPos.y - home.y);
		return len;
	}

	int min_len = 3000;
	int result;
	//현재위치로부터 다른 고객을 만난다.
	for (int i = 0; i < customers.size(); i++)
	{
		if (isVisited[i] == 1)
		{
			continue;
		}
		isVisited[i] = 1;
		int increment = abs(curPos.x - customers[i].x) + abs(curPos.y - customers[i].y);
		min_len = min(min_len, dfs(isVisited, customers, customers[i], home, len + increment));
		isVisited[i] = 0;
	}
	return min_len;
}

int main() {

	int test_case;
	int T;
	int customerSize;
	int result = 0;
	int min_value = 3000;

	freopen("test.txt", "r", stdin);

	Pos customerPos;
	Pos homePos;
	Pos companyPos;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> customerSize;
		cin >> companyPos.x >> companyPos.y;
		cin >> homePos.x >> homePos.y;
		vector<Pos> customers;
		vector<int> isVisited;
		for (int i = 1; i <= customerSize; i++)
		{
			cin >> customerPos.x >> customerPos.y;
			customers.push_back(customerPos);
			isVisited.push_back(0);
		}
		result = dfs(isVisited, customers, companyPos, homePos, 0);
		cout << "# " << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.  
}
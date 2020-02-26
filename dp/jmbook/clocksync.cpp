#include<iostream>
#include<vector>

using namespace std;
int switchInfo[10][5]
{
	{0, 1, 2,0,0},
	{3, 7, 9, 11,0},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},

	{0, 2, 14, 15,0},
	{3, 14, 15,0,0},
	{4, 5, 7, 14, 15},
	{1,2,3,4,5},
	{3,4,5,9,13}
};
int clockSyncRecursive(vector<int>& clockInfos, int clickCount)
{
	bool cmd = false;

	for (int clockTime : clockInfos)
	{
		if (clockTime != 12)
		{
			cmd = true;
			break;
		}
	}
	if (cmd == true)
	{
		return 1;
	}
	if(clickCount == )
	for (int switchNum = 0; switchNum < 10; switchNum++)
	{
		for (int clockIdx = 0; clockIdx < 5; clockIdx++)
		{
			//스위치 적용
			clockInfos[switchInfo[switchNum][clockIdx]] = (clockInfos[switchInfo[switchNum][clockIdx]] + 3) % 13;
			
		}
		clockSyncRecursive(clockInfos, clickCount + 1);
		//스위치 해제
	}

}

int main()
{


	return 0;
}
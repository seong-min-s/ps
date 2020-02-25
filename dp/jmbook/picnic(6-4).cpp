#include<iostream>
#include<vector>

using namespace std;


int MachingFriends(vector<vector<bool>>& isFriends, vector<bool>& isMatched)
{
	int firstFree = -1;
	for (int i = 0; i < 4; i++)
	{
		if (!isMatched[i])
		{
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1)
	{
		return 1;
	}
	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < 4; ++pairWith)
	{
		if (!isMatched[pairWith] && isFriends[firstFree][pairWith])
		{
			isMatched[pairWith] = isMatched[firstFree] = true;
			ret+=MachingFriends(isFriends, isMatched);
			isMatched[pairWith] = isMatched[firstFree] = false;
		}
	}
	return ret;
}

int main()
{
	vector<bool> isMatched(4, false);
	vector<vector<bool>> isFriends = { {0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0} };
	int count = 0;
	count = MachingFriends(isFriends, isMatched);
	cout << count << endl;
	return 0;
}
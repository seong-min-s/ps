/*

target이 words 내에 있어야 함.
begin에서 단어 한 개씩 바꿔서 target이 되어야 함.

모든 경우를 다 탐색하는 dfs로 접근하자



*/

#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int countToMakeTarget = 0;
int mincnt = 987654321;

void calculateCountToMakeTargetRecursive(string subject, string target, int cnt, vector<string>& words, vector<int>& isVisited)
{
	//1개씩 차이가 안나는 경우가 있을 때 종료 ->무시해버림
	//타겟과 서브젝트가 같다면 카운팅한 뒤 종료
	//모든 단어들을 방문했다면 종료

	if (subject == target)
	{
		if (cnt < mincnt)
		{
			mincnt = cnt;
		}
	}

	for (int i = 0; i < words.size(); i++)
	{
		int dif = 0;

		if (isVisited[i])
			continue;

		for (int j = 0; j < words[i].size(); j++)
		{
			if (words[i][j] != subject[j])
			{
				dif++;
			}
		}

		if (dif > 1)
			continue;

		if (dif == 1)
		{
			//dfs
			isVisited[i] = 1;
			calculateCountToMakeTargetRecursive(words[i], target, cnt+1, words, isVisited);
			isVisited[i] = 0;
		}
	}
}

int solution(string begin, string target, vector<string> words)
{
	//타겟이 words 내에 있어야 함.
	
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == target)
		{
			//dfs
			vector<int> isVisited(words.size(), 0);
			calculateCountToMakeTargetRecursive(begin, target, 0, words, isVisited);
			//가짓수 리턴
			return mincnt;
		}
	}
	return 0;
}

int main()
{

}
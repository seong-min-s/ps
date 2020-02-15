/*
*위장
-자료구조 해쉬를 이용한 문제풀이
1.10
2.5
3.5
4.0
5.0
*/
#include<unordered_map>
#include<string>

using namespace std;

int Solution(vector<vector<string>> clothes)
{
	int answer = 1;

	unordered_map<string, int> attributes;

	for (int i = 0; i < clothes.size(); i++)
	{
		attributes[clothes[i][1]]++;
	}
	for (auto e : attributes)
	{
		answer *= (e.second + 1);
	}

	return answer-1;
}
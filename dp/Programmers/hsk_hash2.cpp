/*
*전화번호부 목록
-자료국조 해쉬를 이용한 문제풀이
	1.20
	2.20
	3.5
	4.10
	5.5
*/
#include<unordered_map>
#include<string>

using namespace std;
bool Solution(vector<string> phone_book)
{
	bool answer = true;
	unordered_map<string, int> phoneBookHashMap;
	for (string e : phone_book)
	{
		phoneBookHashMap.insert(make_pair(e, 1));
	}

	for (int i = 0; i < phone_book.size(); i++)
	{
		string tmp = "";
		for (int j = 0; j < phone_book[i].size(); j++)
		{
			tmp += phone_book[i][j];
			if (phoneBookHashMap[tmp] && tmp != phone_book[i])
			{
				answer = false;
				break;
			}
		}
	}

	return answer;
}
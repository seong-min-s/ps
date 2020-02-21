#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
bool isVisited[10001] = { false };
string minPath = "a";
void findPathRecursive(string cur, int ticketIdx, vector<vector<string>> tickets, string paths)
{
	if (ticketIdx == tickets.size())
	{
		if (paths < minPath)
		{
			minPath = paths;
		}
		return;
	}

	for (int i = 0; i < tickets.size(); i++)
	{
		if (!isVisited[i] && tickets[i][0] == cur)
		{
			isVisited[i] = true;
			findPathRecursive(tickets[i][1], ticketIdx + 1, tickets, paths+tickets[i][1]);
			isVisited[i] = false;
		}
	}
}
vector<string> solution(vector<vector<string>> tickets)
{
	vector<string> answer;

	findPathRecursive("ICN", 0, tickets, "ICN");

	for (int i = 0; i < minPath.size(); i+=3)
	{
		answer.push_back(minPath.substr(i, 3));
	}

	return answer;
}

int main()
{
	vector<vector<string>> s = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} };
	vector<string> paths = solution(s);
	
	for (string destination : paths)
	{
		cout << destination << endl;
	}
	return 0;
}
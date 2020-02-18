#include <string>
#include <vector>
#include <iostream>
using namespace std;
int minWays = 1001;
void fromBeginTotargetRecursive(int from, int target, vector<vector<int>> graph, vector<int> isVisited, int count)
{
	isVisited[from] = 1;
	count++;
	if (from == target)
	{
		if (minWays >= count)
		{
			minWays = count;
		}
		return;
	}
	for (int i = 0; i < graph[from].size(); i++)
	{
		if (!isVisited[graph[from][i]])
		{
			fromBeginTotargetRecursive(graph[from][i], target, graph, isVisited, count);
		}
	}

}
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int targetNum;
	bool isIncluded = false;
	vector<int> vs;
	vector<vector<int>> graph(words.size()+1,vs);
	vector<int> isVisited(words.size() + 1);
	//for (string str : words)
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == target)
		{
			isIncluded = true;
			targetNum = i + 1;
		}
	}
	if (!isIncluded)
	{
		return answer;
	}
	words.insert(words.begin(), begin);
	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 0; j < words.size(); j++)
		{
			int difCount = 0;
			for (int k = 0; k < words[i].size(); k++)
			{
				if (words[i][k] != words[j][k])
				{
					difCount++;
				}
			}
			if (difCount == 1)
			{
				graph[i].push_back(j);
			}
		}
	}
	fromBeginTotargetRecursive(0, targetNum, graph, isVisited, 0);
	answer = minWays-1;
	return answer;
}

int main()
{

	//hit->cog => [hot, dot, dog, lot, log, cog] 4
	//hit->cog => [hot, dot, dog, lot, log]	     0
	//string begin, string target, vector<string> words
	vector<string> words = { "hot","dot","dog","lot","log","cog" };
	cout << solution("hit", "cog", words) <<endl;
	return 0;
}
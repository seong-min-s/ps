#include <string>
#include <vector>

using namespace std;

int networkCount = 0;
vector<int> isVisited;

void dfs(int vertex, vector<vector<int>> computers)
{
	isVisited[vertex] = 1;

	for (int v = 0; v < computers.size(); v++)
	{
		if (computers[vertex][v] == 1 && isVisited[v] != 1)
		{
			dfs(v, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;
	isVisited.assign(n, 0);

	for (int v = 0; v < n; v++)
	{
		if (isVisited[v] == 0)
		{
			networkCount++;
			dfs(v, computers);
		}
	}
	answer = networkCount;
	return answer;
}
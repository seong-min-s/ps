#include<iostream>
#include<vector>

using namespace std;

//컴퓨터의 개수 n개,
//모든 노드를 다 방문할 때까지 dfs를 한다.
//
void dfs(vector<int> isVisited, int idx, vector<vector<int>> computers)
{
	isVisited[idx] = 1;

	for (int i = 0; i < computers.size(); i++)
	{
		if (computers[idx][i] == 1 && !isVisited[i])
		{
			dfs(isVisited, i, computers);
		}
	}
}
int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;
	int count = 0;
	vector<int> isVisited(n, 0);

	for (int i = 0; i < n; i++)
	{
		if (isVisited[i] != 0)
		{
			answer++;
			dfs(isVisited, i, computers);
		}
	}
	return answer;
}
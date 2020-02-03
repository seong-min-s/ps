#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<bool> isVisited;
vector<int> vs;
vector<vector<int>> graph;
queue<int> q;

void dfs(int vertex)
{
	if (isVisited[vertex] == 1)
	{
		return;
	}
	cout << vertex << " ";
	isVisited[vertex] = true;

	for (int i = 0; i < graph[vertex].size(); i++)
	{
		dfs(graph[vertex][i]);
	}
}
void bfs(int vertex)
{
	isVisited[vertex] = true;
	q.push(vertex);

	while (!q.empty())
	{
		int value = q.front();
		q.pop();
		cout << value << " ";
		for (int i = 0; i < graph[value].size(); i++)
		{
			if (!isVisited[graph[value][i]])
			{
				q.push(graph[value][i]);
				isVisited[graph[value][i]] = true;
			}
		}
	}
}

int main()
{
	int vertex;
	int edge;
	int startVertex;
	int from, to;

	cin >> vertex >> edge >> startVertex;
	graph.assign((vertex + 1), vs);
	isVisited.assign((vertex + 1), 0);

	for (int i = 0; i < edge; i++)
	{
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	for (int i = 0; i < graph.size(); i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(startVertex);
	isVisited.erase(isVisited.begin(), isVisited.end());
	isVisited.assign((vertex + 1), 0);
	cout << endl;
	bfs(startVertex);

	return 0;
}
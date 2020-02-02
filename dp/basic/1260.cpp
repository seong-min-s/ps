#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<bool> isVisited;
vector<int> vs;
vector<vector<int>> graph;
queue<int> q;
void dfs(int vertex)
{
	cout << vertex << " ";
	isVisited[vertex] = 1;
	for (int i = 1; i < isVisited.size(); i++)
	{
		if (graph[vertex][i] == 1 && isVisited[i] != 1)
		{
			dfs(i);
		}
	}
}
void bfs()
{
	int vertex;
	if (!q.empty())
	{
		vertex = q.front();
		if (isVisited[vertex] == 1)
		{
			return;
		}
		cout <<vertex << " ";
		q.pop();
	}
	else {
		return;
	}
	isVisited[vertex] = 1;
	for (int i = 0; i < isVisited.size(); i++)
	{
		if (graph[vertex][i] == 1 && isVisited[i] != 1)
		{
			q.push(i);
		}
	}
	bfs();
}

int main()
{
	int vertex;
	int edge;
	int startVertex;
	int from, to;

	cin >> vertex >> edge >> startVertex;
	vs.assign(vertex + 1, 0);
	graph.assign(vertex + 1, vs);
	isVisited.assign(vertex + 1, 0);
	q.push(startVertex);
	for (int i = 0; i < edge; i++)
	{
		cin >> from >> to;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}
	dfs(startVertex);
	isVisited.erase(isVisited.begin(), isVisited.end());
	isVisited.assign(vertex + 1, 0);
	cout << endl;
	bfs();

	return 0;
}
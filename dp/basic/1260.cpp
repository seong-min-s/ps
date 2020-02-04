#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_SIZE 1000+1

using namespace std;

bool isVisited[MAX_SIZE];
vector<uint16_t> graph[MAX_SIZE];
queue<uint16_t> q;

void dfs(int vertex)
{
	if (isVisited[vertex] == 1)
	{
		return;
	}
	cout << vertex << " ";
	isVisited[vertex] = true;

	for (uint16_t i = 0; i < graph[vertex].size(); i++)
	{
		dfs(graph[vertex][i]);
	}
}
void bfs(int vertex)
{
	memset(isVisited, false, sizeof(isVisited));
	isVisited[vertex] = true;
	q.push(vertex);

	while (!q.empty())
	{
		int value = q.front();
		q.pop();
		cout << value << " ";
		for (uint16_t i = 0; i < graph[value].size(); i++)
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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int vertex;
	int edge;
	int startVertex;
	int from, to;
	cin >> vertex >> edge >> startVertex;

	for (uint16_t i = 0; i < edge; i++)
	{
		cin >> from >> to;
		graph[from].emplace_back(to);
		graph[to].emplace_back(from);
	}
	for (uint16_t i = 0; i < MAX_SIZE; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(startVertex);

	for (auto i : isVisited)
	{
		i = 0;
	}
	cout << endl;
	bfs(startVertex);

	return 0;
}
#include<iostream>
#include<vector>
#include<cstring>
#define MAXSIZE 100
using namespace std;

vector<int> graph[MAXSIZE];
int isVisited[MAXSIZE];

int findVirusComputerRecursive(int startVertex)
{
	int sum = 0;
	isVisited[startVertex - 1] = 1;

	for (int i = 0; i < graph[startVertex - 1].size(); i++)
	{
		if (isVisited[graph[startVertex - 1][i]] != 1)
		{
			sum++;
			sum += findVirusComputerRecursive(graph[startVertex - 1][i]+1);
		}
	}
	return sum;
}
int main(void)
{
	int nCom;
	int nEdge;
	int from;
	int to;
	int result;
	cin >> nCom;
	cin >> nEdge;
	for (int i = 0; i < nEdge; i++)
	{
		cin >> from >> to;
		graph[from - 1].emplace_back(to - 1);
		graph[to - 1].emplace_back(from - 1);
	}
	memset(isVisited, -1, MAXSIZE * sizeof(int));
	result = findVirusComputerRecursive(1);
	cout << result;
	return 0;
}
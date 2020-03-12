#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
vector<vector<int> > adj;
vector<int> result;
vector<int> isVisited;

void makeGraph(const vector<string>& words)
{
	adj = vector<vector<int> >(26, vector<int>(26, 0));
	int N = words.size();
	for (int j = 0; j < N - 1; j++)
	{
		int len = min(words[j].size(), words[j + 1].size());
		for (int idx = 0; idx < len; idx++)
		{
			if (words[j][idx] != words[j + 1][idx])
			{
				int from = words[j][idx] - 'a';
				int to = words[j + 1][idx] - 'a';
				adj[from][to] = 1;
				break;
			}
		}
	}
}

void dfs(int from)
{
	isVisited[from] = 1;

	for (int to = 0; to < 26; to++)
	{
		if (adj[from][to] && !isVisited[to])
		{
			dfs(to);
		}
	}
	result.push_back(from);
}
vector<int> topology()
{
	int m = adj.size();
	isVisited = vector<int>(m, 0);
	result.clear();
	for (int i = 0; i < 26; i++)
	{
		if (!isVisited[i])
		{
			dfs(i);
		}
	}
	reverse(result.begin(), result.end());

	for (int i = 0; i < 26; i++)
	{
		for (int j = i+1; j < 26; j++)
		{
			if (adj[result[j]][result[i]])
			{
				return vector<int>();
			}
		}
	}
	return result;
}

int main()
{
	int testCase;//1<= TC <=50
	int N;//단어의 수 1<= <=1000
	string word;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		cin >> N;
		vector<string> words(N, "");
		for (int j = 0; j < N; j++)
		{
			cin >> word;
			words.push_back(word);
		}
		makeGraph(words);
		
		vector<int> solution = topology();
		if (solution.empty())
		{
			cout << "INVALID HYPOTHESIS" << endl;
		}
		else
		{
			for (int i = 0; i < 26; i++)
			{
				cout << char(solution[i] + 'a');
			}
			cout << "\n";
		}
	}

}
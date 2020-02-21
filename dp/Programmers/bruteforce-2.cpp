#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
set<int> numberSet;

bool isPrime(int number)
{
	if (number == 1)
		return false;
	if (number == 2)
		return true;
	if (number % 2 == 0)
		return false;

	bool isPrime = true;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
			return false;
	}

	return isPrime;
}
void dfs(string numbers, string prev, bool isVisited[7])
{
	if (prev.size() == numbers.size())
	{
		return;
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		if (!isVisited[i])
		{
			isVisited[i] = true;
			string str = prev + numbers[i] ;
			int iNumber = stoi(str);
			if (isPrime(iNumber))
			{
				numberSet.emplace(iNumber);
			}
			dfs(numbers, str, isVisited);
			isVisited[i] = false;
		}
	}
}
int solution(string numbers) {
	int answer = 0;
	bool isVisited[7] = { false };
	dfs(numbers, "", isVisited);
	return answer;
}

int main()
{

	cout << solution("011");
}
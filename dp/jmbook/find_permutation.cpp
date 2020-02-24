/*n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//n:전체 원소의 수
//picked : 지금까지 고른 원소들의 번호
//toPick : 더 고를 원소의 수
//일 때, 앞으로 toPick 개의 원소를 고르는 모든 방법을 출력한다.
void printPicked(vector<int>& v)
{
	for (int element : v)
	{
		cout << element << " ";
	}
	cout << endl;
}
void pick(int n, vector<int>& picked, int toPick)
{
	//기저 사례 : 더 고를 원소가 없을 때 고른 원소들을 출력한다.
	if (toPick == 0)
	{
		printPicked(picked);
		return;
	}
	//고를 수 있는 가장 작은 번호를 계싼한다.
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	//이 단계에서 원소 하나를 고른다.
	for (int next = smallest; next < n; ++next)
	{
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}
int main()
{
	vector<int> testCase;
	pick(5, testCase, 3);
	
	//abc를 조합으로 도출해내기
	vector<char> testCase2 = { 'a','b','c' };
	//next_permutation(testCase2.begin(), testCase2.end());
	cout << "The 3! possible permutations with 3 elements:\n";
	do {
		std::cout << testCase2[0] << ' ' << testCase2[1] << ' ' << testCase2[2] << '\n';
	} while (next_permutation(testCase2, testCase2.begin() + 3));
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int numbers[5] = { 1,1,1,1,1 };
int counts = 0;

//+1 이나 -1을 해서 target number를 만든다.
//항상해야하는 일은 연산, 자료 numbers를 이용한다.
//기저사례는 모든 자료를 다 사용했을 때 종료한다.
void getWaysRecursive(vector<int> numbers, int idx, int subject, int targetNumber)
{

	if (idx == numbers.size())
	{
		if (subject == targetNumber)
		{
			counts++;
		}
		return;
	}

	getWaysRecursive(numbers, idx + 1, subject + numbers[idx], targetNumber);

	getWaysRecursive(numbers, idx + 1, subject - numbers[idx], targetNumber);
}

int solution(vector<int> numbers, int target) {
	getWaysRecursive(numbers, 0, 0, 3);
	return counts;
}

int main() {
	vector<int> v(numbers, numbers + 5);
	std::cout << solution(v, 3) << endl;
}
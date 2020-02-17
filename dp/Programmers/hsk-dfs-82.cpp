#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = 1 << numbers.size();

	for (int i = 0; i < size; i++) {
		int temp = 0;
		for (int j = 0; j < numbers.size(); j++)
		{
			if (i & (1 << j))
			{
				temp -= numbers[j];
			}
			else
			{
				temp += numbers[j];
			}
		}
		if (temp == target)
		{
			answer++;

		}
	}
    return answer;
}
int main()
{
	vector<int> numbers;
	numbers.emplace_back(1);
	numbers.emplace_back(1);
	numbers.emplace_back(1);
	numbers.emplace_back(1);
	numbers.emplace_back(1);

	cout << solution(numbers, 5)<<endl;
	return 0;
}

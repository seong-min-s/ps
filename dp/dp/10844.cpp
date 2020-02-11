#include<iostream>
using namespace std;

int cache[10][101] = { 0 };
int fun(int num, int len)
{
	int& ret = cache[num][len];
	if (ret != 0)
		return ret;
	if (num < 0)
		return 0;
	if (num > 9)
		return 0;
	if (len == 1) {
		ret = 1;
		return ret;
	}

	ret = fun(num - 1, len - 1) + fun(num + 1, len - 1);
	return ret;
}

int main(void)
{
	int N;
	int sum = 0;

	cin >> N;
	for (int i = 1; i <= 9; i++)
	{
		fun(i, N);
	}
	for (int i = 1; i <= 9; i++)
	{
		sum += cache[i][N];
	}
	cout << sum % 1000000000;
	return 0;
}
#include<iostream>
using namespace std;

int main(void)
{
	int n,a, b, c;
	a = 1, b = 2, c = 0;
	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		c = (a + b) % 15746;
		a = b;
		b = c;
	}
	cout << c;
	return 0;
}
#include<iostream>
using namespace std;
long long p[90] = { 0 };
long long pivonach(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	if (p[n] != 0)
		return p[n];
	else {
		p[n] = pivonach(n - 1) + pivonach(n - 2);
		return p[n];
	}
}
int main()
{
	int n;
	cin >> n;

	cout << pivonach(n) << endl;
	return 0;
}
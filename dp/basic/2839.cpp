#include<iostream>
using namespace std;

int main(void)
{
	int n, p, q, r;

	cin >> n;
	p = n / 5;
	q = n % 5;
	r = q % 3;

	while (r != 0)
	{
		p--;
		q += 5;
		r = q % 3;
	}
	r = (p < 0) ? -1 : p + q / 3;
	cout << r;

	return 0;
}
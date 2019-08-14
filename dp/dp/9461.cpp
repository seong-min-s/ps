#include<iostream>
using namespace std;
long long p[101] = { 0 };
int main(void)
{
	int T,N;
	p[1] = p[2] = p[3] = 1;
	p[4] = p[5] = 2;
	cin >> T;

	while (T--)
	{
		cin >> N;
		for (int i = 6; i <=N; i++)
		{
			if(p[i]==0)
				p[i] = p[i - 1] + p[i - 5];
		}
		cout << p[N] << endl;
	}
	
	return 0;
}

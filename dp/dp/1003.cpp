#include<iostream>
using namespace std;

int zerocount[41] = { 0 };
int onecount[41] = { 0 };

int main()
{
	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		zerocount[0] = 1;
		onecount[1] = 1;

		cin >> n;
	
		for (int j = 2; j <=n; j++)
		{
			onecount[j] = onecount[j - 1] + onecount[j - 2];

			zerocount[j] = zerocount[j - 1] + zerocount[j - 2];
		}
		cout << zerocount[n] << " " << onecount[n] << endl;
	}
	return 0;
}
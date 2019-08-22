#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	vector<int> v1(n, 0);
	vector<int> v2(n, 0);
	vector<int> result(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
	}
	for (int i = 0; i < n; i++) 
	{
		cin >> v2[i];
	}
		
	for (int i = 0; i < n; i++) {
		result[i]=(v1.at(i) | v2.at(i));
		cout << result[i];
	}
	vector<vector<int>> v(n,vector<int>(n,0));

	for (int i = 0; i < n; i++)
	{
		int temp = result[i];
		for (int j = 0; j < n; j++)
		{
			v[i][j] = temp % 2;
			temp = temp / 2;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int temp = result[i];
		for (int j = n-1; j >= 0; j--)
		{
			if (v[i][j] == 1)
			{
				cout << "#";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
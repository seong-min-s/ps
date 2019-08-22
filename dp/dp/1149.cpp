#include<iostream>
#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;
int main(void)
{
	int T;
	int get;
	int p[1001][3] = { 0 };
	int d[1001][3] = { 0 };
	cin >> T;
	for (int i=0; i<T; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> get;
			p[i][j] = get;
		}
	}
	d[0][0] = d[0][1] = d[0][2] =p[0][ 0]=p[0][1]=p[0][2]=0;
	for (int i = 1; i <=T; i++)
	{
		d[i][0] = MIN(d[i - 1][1], d[i - 1][2]) + p[i][0];
		d[i][1] = MIN(d[i - 1][0], d[i - 1][2]) + p[i][1];
		d[i][2] = MIN(d[i - 1][0], d[i - 1][1]) + p[i][2];
	}
	cout << MIN(MIN(d[T][0], d[T][1]), d[T][2])<<endl;
	return 0;
}
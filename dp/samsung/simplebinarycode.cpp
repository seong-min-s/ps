#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

string code[9] = { "0001101" ,"0011001" ,"0010011" ,"0111101" ,"0100011" ,"0110001" ,"0101111" ,"0111011" ,"0001011" };
int main()
{
	int tc, m, n;
	int c;
	int count;
	vector<stack<int,vector<int>>> v;
	int a[80] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,1,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0 };
	vector<int> vv(a,a+sizeof(a)/sizeof(int));
	stack<int,vector<int>> row(vv);
	//stack<int> row;
	//cin >> tc;
	tc = 1;
	for (int i = 0; i < tc; i++)
	{
		//cin >> m >> n;
		//데이터 삽입
		m = 1, n = 80;
		int cache;
		for (int y = 0; y < m; y++)
		{
			/*
			for (int x = 0; x < n; x++)
			{
				cin >> c;
				row.push(c);
			}*/
			/*암호 추출, 암호의 마지막은 전부 1로 끝난다.*/
			while (row.top() != 1)
			{
				row.pop();
			}
			if (!row.empty())
			{
				v.push_back(row);
			}
		}

		int sum = 0;
		int odd_sum = 0;
		int even_sum = 0;
		for (int j = 0; j < 8; j++) {
			string temp;
			for (int i = 0; i < 7; i++) {
				temp = to_string(v[0].top())+temp;
				v[0].pop();
			}
			int where = 0;
			for (int i = 0; i < 9; i++)
			{
				if (code[i] == temp)
				{
					where = i;
					break;
				}
			}

			if (j == 0)
			{
				sum += where;
			}
			else if (j % 2 == 0) {
				even_sum += where;
			}
			else {
				odd_sum += where;
			}
		}
		int result_sum = sum + even_sum + odd_sum;
		sum += (3 * odd_sum + even_sum);
		if (sum % 10 != 0) {
			cout << "0" << endl;
		}
		else {
			cout << result_sum << endl;
		}

		v.erase(v.begin(), v.end());
	}
	return 0;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(void)
{
	int hour = 9;
	int minute = 0;

	int n, t, m;
	string temp="123";
	vector<string> crews;
	cin >> n >> t >> m;
	cin.ignore(256, '\n');

	while (!temp.empty())
	{
		getline(cin,temp);
		crews.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{

	}


	return 0;
}
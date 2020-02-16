#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;//610 106

vector<string> stringNumbers;
bool comparator(const string& a, const string& b)
{
	return b + a < a + b;
}
string Solution(vector<int>& array)
{
	string answer =	"";
	for (int i : array)
	{
		stringNumbers.push_back(to_string(i));
	}
	sort(stringNumbers.begin(), stringNumbers.end(), comparator);

	for (string s : stringNumbers)
	{
		answer += s;
	}
	return answer;
}
int main()
{
	vector<int> array;
	array.push_back(6);
	array.push_back(10);
	array.push_back(2);

	cout << Solution(array) << endl;

	return 0;
}
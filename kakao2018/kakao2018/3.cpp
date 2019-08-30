#include<iostream>
#include<string>
#include<string.h>
#include<queue>
#include<list>
#include<algorithm>
using namespace std;

int main(void)
{
	int result=0;
	string mycache[2] = { "","" };
	string cities_array[10] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	for (int i = 0; i < 2; i++)
	{
		transform(mycache[i].begin(), mycache[i].end(),mycache[i].begin(), tolower);
	}
	for (int i = 0; i < 10; i++)
	{
		transform(cities_array[i].begin(), cities_array[i].end(), cities_array[i].begin(), tolower);
		//cout << cities_array[i] << endl;
	}
	list<string> cities(cities_array,cities_array+sizeof(cities_array)/sizeof(string));
	list<string> ca(mycache, mycache + sizeof(mycache) / sizeof(string));

	queue<string, list<string>> ca_q(ca);
	queue<string,list<string>> cities_q(cities);//도시저장 큐

	
	if (ca.size() == 0)
	{
		return result = 5 * cities.size();
	}
	while (!cities_q.empty())
	{
		auto i = find(ca.begin(), ca.end(), cities_q.front());
		if (i == ca.end())//도시에 없는 경우
		{
			result += 5;
			ca_q.push(cities_q.front());
			cities_q.pop();
		}else {
			result += 1;
			ca_q.pop();
			ca_q.push(cities_q.front());
			cities_q.pop();
		}
	}
	cout << result << endl;

	return 0;
}
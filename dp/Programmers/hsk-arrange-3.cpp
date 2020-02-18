#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int count = 0;
	int hIdx;
	sort(citations.begin(), citations.end(), greater<int>());
	hIdx = citations[0];
	while (hIdx--)
	{
		count = 0;
		for (int accepted : citations)
		{
			if (accepted >= hIdx)
			{
				count++;
			}
		}
		if (hIdx <= count)
		{
			answer = count;
			break;
		}
	}
	/*
	for(int h=1; h<10001; h++)
	{
		count=0;
		for(int acceptedNumber : citations)
		{
			if(acceptedNumber>=h)
			{
				count++;
			}
		}
		if(h==count)
		{
			answer = count;
			break;
		}
	}*/
	return answer;
}

int main(void)
{
	vector<int> citation;

	citation.push_back(6);
	citation.push_back(5);
	citation.push_back(1);
	citation.push_back(0);

	cout << solution(citation) << endl;
	return 0;
}
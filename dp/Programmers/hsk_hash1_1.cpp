#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> strMap;
	for (auto elem : completion)
	{
		if (strMap.end() == strMap.find(elem))
			strMap.insert(make_pair(elem, 1));
		else
			strMap[elem]++;
	}

	
	for (auto elem : participant)
	{
		if (strMap.end() == strMap.find(elem))
		{
			answer = elem;
			break;
		}
		else
		{
			strMap[elem]--;
			if (strMap[elem] < 0)
			{
				answer = elem;
				break;
			}
		}
	}
	return answer;
}

int main(void)
{
	string participantA[3] = { "leo", "kiki", "eden" };
	string participantB[5] = { "marina", "josipa", "nikola", "vinko", "filipa" };
	string participantC[4] = {"mislav", "stanko", "mislav", "ana"};
	//string participantC[6] = { "a", "b", "c", "x", "y", "z" };

	string completionA[2] = { "eden", "kiki" };
	string completionB[4] = { "josipa", "filipa", "marina", "nikola" };
	string completionC[3] = { "stanko", "ana", "mislav" };
	//string completionC[5] = { "a", "b", "x", "y", "z" };

	vector<string> tempPar(participantA, participantA + 3);
	vector<string> tempCom(completionA, completionA + 2);

	//vector<string> tempPar(participantB, participantB + 5);
	//vector<string> tempCom(completionB, completionB + 4);

	cout << solution(tempPar, tempCom) << endl;

	tempPar.assign(participantB, participantB + 5);
	tempCom.assign(completionB, completionB + 4);
	cout << solution(tempPar, tempCom) << endl;

	tempPar.assign(participantC, participantC + 4);
	tempCom.assign(completionC, completionC + 3);
	cout << solution(tempPar, tempCom) << endl;

	return 0;
}
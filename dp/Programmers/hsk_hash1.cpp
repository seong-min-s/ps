#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	int i;
	
	answer = participant.at(participant.size()-1);

	for (i = 0; i < completion.size(); i++)
	{
		if (participant[i] != completion[i])
		{
			answer = participant[i];
		}
	}
	return answer;
}
int main()
{
	string participantA[3] = {"leo", "kiki", "eden"};
	string participantB[5] = {"marina", "josipa", "nikola", "vinko", "filipa"};
	//string participantC[4] = {"mislav", "stanko", "mislav", "ana"};
	string participantC[6] = { "a", "b", "c", "x", "y", "z" };

	string completionA[2] = { "eden", "kiki" };
	string completionB[4] = { "josipa", "filipa", "marina", "nikola" };
	//string completionC[3] = { "stanko", "ana", "mislav" };
	string completionC[5] = { "a", "b", "x", "y", "z" };

	vector<string> tempPar(participantA, participantA+3);
	vector<string> tempCom(completionA, completionA+2);

	//vector<string> tempPar(participantB, participantB + 5);
	//vector<string> tempCom(completionB, completionB + 4);

	cout << solution(tempPar, tempCom) << endl;

	tempPar.assign(participantB, participantB + 5);
	tempCom.assign(completionB, completionB + 4);
	cout << solution(tempPar, tempCom) << endl;

	tempPar.assign(participantC, participantC + 6);
	tempCom.assign(completionC, completionC + 5);
	cout << solution(tempPar, tempCom) << endl;

	return 0;
}
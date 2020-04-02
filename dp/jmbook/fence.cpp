#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
현재 판자 기준으로 판자들을 지나치다가 낮은 판자가 보인다면,
낮은 판자의 전까지 넓이를 구한다. 넓이는 최대 넓이로 계속 갱신한다.

높은 판자가 보인다면 판자들을 지나친다.

판자의 수가 최대 20000개이기 때문에 최악의 경우 400000000
 4억... 4초
 
 분할정복?

 <넓이를 더한 뒤 직사각형의 최대 크기를 계산하기>

현재 판자 now, 다음판자 비교next

now <= next : now기준으로 계쏙해서 너비를 늘린다. 그리고 next 기준으로 새롭게
너비를 구한다.

now > next : 현재까지의 너비를 구한다.(기저사례)

넓이, 현재, 다음,
 */
int maxRec = 0;
void calRectMaxSizeRecursive(int now, int size, vector<int>& h)
{
	int next;
	next = now + 1;

	//종료조건
	if (now > h.size() - 1)
	{
		maxRec = max(maxRec, size);
		return;
	}
	//재귀함수 호출 : 넓이를 계산한다.
	if (h[now] > h[next])
	{
		//현재에서 멈춘다.
		maxRec = max(maxRec, size + h[now]);
		//다음 너비로 더해준다.
		calRectMaxSizeRecursive(now + 1, size + h[next], h);
	}
	
	if(h[now] <= h[next])
	{
		//현재 너비를 이어간다.
		calRectMaxSizeRecursive(now + 1, size + h[now], h);
		//새롭게 너비를 구한다.
		calRectMaxSizeRecursive(now + 1, 0, h);
	}
}

int main()
{
	int tc;
	int n;
	int value;
	vector<int> h;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		h = vector<int>();
		while (n--)
		{
			cin >> value;
			h.push_back(value);
		}
		maxRec = 0;
		calRectMaxSizeRecursive(0,0,h);
		cout << maxRec << endl;
	}
	return 0;
}
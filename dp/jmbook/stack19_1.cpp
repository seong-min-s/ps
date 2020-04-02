#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

//�� ������ ���̸� �����ϴ� �迭
vector<int> h;

int solveStack()
{
	stack<int> remaining;
	h.push_back(0);
	int ret = 0;
	for (int i = 0; i < h.size(); ++i)
	{
		//���� �ִ� ���ڵ� �� ������ ���ڰ� h[i]���� ���ٸ�
		//�� ������ �ִ�簢���� i���� ������.
		while (!remaining.empty() && h[remaining.top()] >= h[i])
		{
			int j = remaining.top();
			remaining.pop();
			int width = -1;
			//j��° ���� ���ʿ� ���ڰ� �ϳ��� �� ���� �ִ� ��� left[j]=-1,
			//�ƴ� ��� left[j]=���� �ִ� ���� �� ���� �����ʿ� �ִ� ������ ��ȣ�� �ȴ�.
			if (remaining.empty())
			{
				width = i;
			}
			else
			{
				width = (i - remaining.top() - 1);
			}
			ret = max(ret, h[j] * width);
		}
		remaining.push(i);
	}
	return ret;
}
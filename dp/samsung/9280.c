#include <stdio.h>
#include <stdlib.h>
int queSize;
int front;
int rear;
int* queue;
int initQue(int size)
{
	queSize = size;
	front = 0;
	rear = 0;
	queue = (int*)malloc(sizeof(int) * size);
}
int enque(int value)
{
	if ((front + 1) % queSize == rear)
	{
		return 0;
	}
	queue[front] = value;
	front = (front + 1) % queSize;
	return 1;
}
int deque()
{
	int result;
	if (front == rear)
	{
		return 0;
	}
	result = queue[rear];
	rear = (rear + 1) % queSize;
	return result;
}
int main(void)
{
	int test_case = 0;
	int T = 0;
	int* parkingLot = NULL;
	int* isParked = NULL;
	int* carWeight = NULL;
	int n = 0, m = 0;
	int carNum;
	int cost;
	int err_num;

	scanf_s("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf_s("%d %d", &n, &m); //n은 주차장개수 m은 차량 개수
		initQue(2 * m + 1);
		parkingLot = (int*)malloc(sizeof(int) * n);
		isParked = (int*)calloc(n, sizeof(int));
		carWeight = (int*)malloc(sizeof(int) * m);
		cost = 0;

		for (int i = 0; i < n; i++)
		{
			scanf_s("%d", &parkingLot[i]);
		}
		for (int i = 0; i < m; i++)
		{
			scanf_s("%d", &carWeight[i]);
		}
		for (int i = 0; i < 2 * m; i++)
		{
			scanf_s("%d", &carNum);
			enque(carNum);
		}
		
		while ((carNum = deque())!=0)
		{
			if (carNum < 0)
			{
				carNum = -carNum;
				for (int j = 0; j < n; j++)
				{
					if (isParked[j] == carNum)
					{
						cost += parkingLot[j] * carWeight[carNum - 1];
						isParked[j] = 0;
						break;
					}
				}
			}
			else if (carNum > 0)
			{
				for (int j = 0; j < n; j++)
				{
					if (isParked[j] == 0)
					{
						isParked[j] = carNum;
						break;
					}
				}
			}
		}

		printf("#%d %d\n", test_case, cost);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
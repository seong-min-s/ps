#include<stdio.h>
int main()
{
	int n3=0, n5=0;
	int sum=0, min=1000, count = -1;
	int i, j;
	scanf("%d", &sum);
	
	n3 = sum/3;
	n5 = sum/5;

	for(i = 0; i <= n3; i++)
	{
		for(j = 0; j <= n5; j++)
		{
			if((i*3 + j*5)==sum)
			{
				count++;
				if(i+j < min)
				{
					min = i+j;
				}
			}
		}
	}
	if(count > -1)
	{
		printf("%d\n",min);
	}else
		printf("%d\n",count);

	return 0;
}

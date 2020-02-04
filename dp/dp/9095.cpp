/*1+2+3¥ı«œ±‚<baekjoon>*/
#include<cstdio>
int substractRecursive(int subject, int factor)
{
	int sum = 0;
	subject = subject - factor;
	if (subject == 0)
	{
		return 1;
	}
	else if (subject < 0)
	{
		return 0;
	}
	sum = substractRecursive(subject, 1) + substractRecursive(subject, 2) + substractRecursive(subject, 3);
}
int main(void)
{
	int T = 0;
	int num = 0;
	int result = 0;
	scanf_s("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf_s("%d", &num);
		result = substractRecursive(num, 0);
		printf("%d\n", result);
	}
	return 0;
}
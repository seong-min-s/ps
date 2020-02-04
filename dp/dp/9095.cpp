/*1+2+3´õÇÏ±â<baekjoon>*/
#include<cstdio>
int sum[12] = { 0 };
int substractRecursive(int subject)
{
	if (subject == 0)
		return 1;
	else if (subject < 0)
		return 0;

	int& ret = sum[subject];

	if (ret != 0)
		return ret;

	ret = substractRecursive(subject - 1) + substractRecursive(subject - 2) + substractRecursive(subject - 3);
	return ret;
}
int main(void)
{
	int T = 0;
	int num = 0;
	int result[12] = { 0 };
	scanf_s("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf_s("%d", &num);
		result[i] = substractRecursive(num);
		printf("%d\n", result[i]);
	}
	return 0;
}
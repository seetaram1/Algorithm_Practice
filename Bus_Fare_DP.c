#include <stdio.h>
#define MAX 5005
#define INF 9999
int I[MAX], B[MAX];
int N;
int main(void)
{
	int TestCase, T, current, i, j, min;
	//freopen("simple.txt", "r", stdin);
	//freopen("Seetaram.txt", "r", stdin);
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (TestCase = 1; TestCase <= T; TestCase++)
	{
		for (i = 1; i <= 10; i++)
		{
			scanf("%d", &I[i]);
		}
		scanf("%d", &N);
		for (i = 11; i <= N; i++)
		{
			I[i] = I[10] + I[i - 10];
		}
		B[0] = 0;
		

		for (i = 1; i <= N; i++)
		{
			min = INF;
			for (j = i; j >0; j--)
			{
				if (min > I[j] + B[i - j])
					min = I[j] + B[i - j];
			}
			B[i] = min;
		}
		

		printf("%d\n", B[N]);
		
		for (i = 0; i <= N; i++)
		{
			I[i] = 0;
			B[i] = 0;
		}
	}
	return 0;
}
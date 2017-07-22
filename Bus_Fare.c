#include <stdio.h>
#define MAX 5005
#define MAX_QUE 15005
#define INF 9999
int I[MAX], B[MAX];
int QUE[MAX_QUE];
int front = -1, rear = -1;
int N;
int main(void)
{
	int TestCase, T, current,i,j;
	freopen("Seetaram.txt", "r", stdin);
	//freopen("sample_input.txt", "r", stdin);
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
			I[i]=I[10]+I[i-10];
		}
		B[0] = 0;
		for (int i = 1; i <= N; i++)
		{
			B[i]=INF;
		}
		rear++;
		QUE[rear] = 0;
		while (front != rear)
		{
			//for (j = 0; j <= N; j++)
			//{
				front++;
				current = QUE[front];
				//current = QUE[j];
				//;
				for (i = current + 1; i <= N; i++)
				{
					if ((B[i] == INF) || (B[i] > B[current] + I[i - current]))
					{
						B[i] = B[current] + I[i - current];
						rear++;
						QUE[rear] = i - current;
					}
				}
			//}
			}
			
		printf("%d\n", B[N]);
		for (i = 0; i < rear; i++)
		{
			QUE[i] = 0;
		}
		front = -1;
		rear = -1;
		for (i = 0; i <= N; i++)
		{
			I[i] = 0;
			B[i]= 0; 
		}
	}
	return 0;
}
#include <stdio.h>
#define MAX 105
#define INF 99999
int visited[MAX];
int A[MAX][MAX];
int N;
void DFS_BackTrack(int i, int sum, int count);
int currentMin = 9999;
int main(void)
{
	int TestCase, T;
	//freopen("sample_input.txt", "r", stdin);
	freopen("Seetaram.txt", "r", stdin);
	//freopen("second.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (TestCase = 1; TestCase <= T; TestCase++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			visited[i] = 0;
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &A[i][j]);
				if (A[i][j] == 0)
				{
					A[i][j] = INF;
				}
			}
		}
		int j = 0;
		for (int i = 0; i < N; i++)
		{
			A[i][N] = A[i][j];
		}
		visited[N] = 0;
		DFS_BackTrack(0, 0,0);
		printf("%d\n", currentMin);
		currentMin = INF;
	}
	return 0;
}
void DFS_BackTrack(int i, int sum,int count)
{
	visited[i] = 1;
	count++;
	if (sum > currentMin)
		return;
	if (count == N)
	{
		sum = sum + A[i][N];
		if (currentMin > sum)
			currentMin = sum;
		return;
	}
	else
	{
		for (int j = 0; j < N; j++)
		{
			if ((visited[j] != 1) && (A[i][j] != INF))
			{
				DFS_BackTrack(j, sum + A[i][j], count);
				visited[j] = 0;
				//count--;
			}

		}
	}	
}
	
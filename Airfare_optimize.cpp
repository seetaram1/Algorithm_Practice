#include <stdio.h>
#define MAX 105
#define INF 99999
int source[MAX];
int Result[MAX];
bool ispick[MAX];
int A[MAX][MAX];
int N;
void permutation(int selected, int sum);
int currentMin = 9999;
int main(void)
{
	int TestCase, T;
	//freopen("sample_input.txt", "r", stdin);
	freopen("Seetaram.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (TestCase = 1; TestCase <= T; TestCase++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &A[i][j]);
				if (A[i][j] == 0)
				{
					A[i][j] = INF;
				}
			}
			source[i] = i;
			ispick[i] = false;
		}
		ispick[0] = true;
		ispick[N] = true;
		Result[N] = 0;
		permutation(1,0);
		printf("%d\n", currentMin);
		currentMin = INF;
	}
	return 0;
}
	void permutation(int selected,int sum)
	{
		if (selected == N)
		{
			if (sum < currentMin)
				currentMin = sum;
			
		}
		else
		{
			for (int i = 1; i < N; i++)
			{
				if (ispick[i] == true)continue;
				ispick[i] = true;
				Result[selected] = source[i];
				//if (ispick[i] == true)
					permutation(selected + 1, (ispick[i] == false)? sum:sum + A[source[i]][source[i+1]]);
					sum = sum - A[source[i]][source[i + 1]];
				ispick[i] = false;
			}		
		}
	
	}
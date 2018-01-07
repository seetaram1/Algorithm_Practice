#include <stdio.h>
#define que_len 100
#define MAX 500
int que[que_len];
int front = -1, rear = -1;
int minPress[MAX];
int min = 9999;
int max = 0;
int N, Steps[MAX];
int StartIndex, EndIndex;
void BFS(void);
int minSteps = 9999;
void DFS(int current, int steps);
int Target;
bool visited[500];
//int shift;
int MyAbs(int a);
#define shift 100
int main(void)
{
	int TestCase, T,Start,temp;
	freopen("remote_control.txt", "r", stdin);
	scanf("%d", &T);
	for (TestCase = 1; TestCase <= T; TestCase++)
	{
		scanf("%d %d", &Start,&Target);
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &Steps[i]);
			if (min > Steps[i])
				min = Steps[i];
			if (max < Steps[i])
				max = Steps[i];
		}
		if (min > max)
		{
			temp = max;
			max = min;
			min = temp;
		}
		
		StartIndex = min+shift;
		EndIndex = Target + max+shift;
		
		for (int i = StartIndex; i <= EndIndex; i++)
			minPress[i] = 9999;
		que[++rear] = Start+shift;
		minPress[Start+shift] = 0;
		BFS();
		//DFS(Start, 0);
		printf("%d", minPress[Target+shift]);
	}
}
int MyAbs(int a) {
	if (a < 0)
		return a*(-1);
	else
		a;
}
void BFS(void)
{
	int i,current,next;
	while (front!=rear)
	{
		current = que[++front];
		for (i = 0; i < N; i++)
		{
			next = current + Steps[i];
			
			if ((next <= EndIndex ) && (next >= StartIndex))
			{
				//printf("%d %d ", next, current);
				if (minPress[next] > minPress[current] + 1)
				{
					minPress[next] = minPress[current] + 1;
					que[++rear] = next;
				}
			}			
		}
	}
}


/*
void DFS(int current,int steps)
{
	int next;
	if (steps > minSteps)
		return;
	if (current == Target)
	{
		if (minSteps > steps)
			minSteps = steps;
		return;
	}
	visited[current] = true;
	for (int i = 0; i < N; i++)
	{
		next = current + Steps[i];
		if ((next < EndIndex) && (next > StartIndex) && visited[next]==false)
			DFS(next, steps + 1);
	}	
}
*/
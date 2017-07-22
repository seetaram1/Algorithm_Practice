#include<stdio.h>
fillCharacterArray(int A, char *FilledArray);
AddCharacterArray(char *A, char *B, char *Output);
int main()
{
	int A, B,T,i;
	A = 9999;
	char CharA[100],CharB[100],CharC[100];
	int Mask = 0x000F;
	FILE* InputFile;
	InputFile = fopen("Seetaram.txt", "r");
	fscanf(InputFile, "%d", &T);
	for (i = 1; i <= T; i++)
	{
		fscanf(InputFile, "%d", &A);
		fscanf(InputFile, "%d", &B);
		int j = 0;
		fillCharacterArray(A, &CharA);
		printf("%s", CharA);
		fillCharacterArray(A, &CharB);
		printf("%s", CharB);	
		AddCharacterArray(&CharA, &CharB, &CharC);
	}
}
fillCharacterArray(int A, char *FilledArray)
{
	int mask = 0x000F;
	char digit = 0;
	int CharIndex = 0;
	while (A != 0)
	{
		digit = A%10;
		digit += 48;
		A = A/10;
		FilledArray[CharIndex] = digit;
		CharIndex++;
	}
	FilledArray[CharIndex] = '\0';
	printf("%s", FilledArray);
}
AddCharacterArray(char *A, char *B, char *Output)
{
	int lenght1, lenght2, l1, l2, CharIndex=0;
	lenght1 = strlen(A);
	lenght2 = strlen(B);
	l1 = lenght1;
	l2 = lenght2;
	char Mask = 0x0f;
	while (l1 != 0 || l2 != 0)
	{
		Output[CharIndex]= (A[CharIndex]-48) + (B[CharIndex]-48);
		Output[CharIndex] += 48;
		l1--;
		l2--;
		CharIndex++;
	}
	/*if (l1 == 0)
	{
		RemLen = lenght2 - l2;
		copy string()
	}
	if (l2 == 0)
	{
		RemLen = lenght1 - l1;
		copy string
	}*/
	Output[CharIndex] = '\0';
	printf("%s", Output);
}
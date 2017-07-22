#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*fillCharacterArray(long long A, char *FilledArray);*/
AddCharacterArray(char *A, char *B, char *Output);
int main()
{
	int T,i;	
	char CharA[100],CharB[100],CharC[100], Output[101];
	FILE* InputFile;
	InputFile = fopen("Seetaram.txt", "r");
	fscanf(InputFile, "%d", &T);
	for (i = 1; i <= T; i++)
	{
		fscanf(InputFile, "%s", &CharA);
		fscanf(InputFile, "%s", &CharB);		
		AddCharacterArray(&CharA, &CharB, &CharC);
		int length = strlen(CharC);
		int l = 0;
		while (l != length)
		{
			Output[l] = CharC[length - l-1];			
			l++;
		}	
		Output[l] = '\0';
		printf("Output=%s", Output);
		getch();
	}
}
/*fillCharacterArray(long long A, char *FilledArray)
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
	//printf("%s", FilledArray);
}*/
AddCharacterArray(char *A, char *B, char *Output)
{
	int lenght1, lenght2, l1, l2, CharIndex=0,AInt,BInt,SumInt;
	
	lenght1 = strlen(A);
	lenght2 = strlen(B);
	l1 = lenght1;
	l2 = lenght2;
	char Mask = 0x0f;
	int Carry = 0;
	char SumChar[100];
	char* SumCharPtr = &SumChar[0];
	//char CharA[100], CharB[100], CharC[100];
	//char *ChrPtr = &CharC[0];
	while (l1 != 0 && l2 != 0)
	{
		SumInt = (A[CharIndex]-48) + (B[CharIndex]-48)+ Carry;
		//AInt =atoi(&A[CharIndex]);
		//BInt =atoi(&B[CharIndex]);
		//SumInt = AInt + BInt+ Carry;
		Carry = SumInt / 10;
		SumInt = SumInt % 10;
		Output[CharIndex] = SumInt+48;
		//SumCharPtr = _itoa(SumInt, SumChar[CharIndex],10);
		l1--;
		l2--;
		CharIndex++;
	}
	if (l1 != 0)
	{
		while (l1 != 0)
		{			
				SumInt = ((A[CharIndex] - 48) + Carry);
				Carry = SumInt / 10;
				SumInt = SumInt % 10;
				Output[CharIndex] = SumInt + 48;
				l1--;
				CharIndex++;
		}
		
	}
	if (l2 != 0)
	{
		while (l2 != 0)
		{
			SumInt = ((A[CharIndex] - 48) + Carry);
			Carry = SumInt / 10;
			SumInt = SumInt % 10;
			Output[CharIndex] = SumInt + 48;
			l2--;
			CharIndex++;
		}

	}
	if (Carry)
	{
		Output[CharIndex] = Carry+48;
		CharIndex++;
	}
	Output[CharIndex] = '\0';
	printf("Temp=%s", Output);
}
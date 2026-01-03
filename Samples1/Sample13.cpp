#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	int i, j;
	scanf("%d", &t);
	char arr[t][6];
	int fre[4];
	for(i=0;i<4;i++)
	{
		fre[i] = 0;
	}
	for(i=0;i<t;i++)
	{
		scanf("%s", arr[i]);
	}
	for(i=0;i<t;i++)
	{
		if(strcmp(arr[i],"AC") == 0)
			fre[0]++;
		if(strcmp(arr[i],"WA")==0)
			fre[1]++;
		if(strcmp(arr[i],"TLE")==0)
			fre[2]++;
		if(strcmp(arr[i],"RE")==0)
			fre[3]++;
	}
	printf("AC x %d\n", fre[0]);
	printf("WA x %d\n", fre[1]);
	printf("TLE x %d\n", fre[2]);
	printf("RE x %d\n", fre[3]);
}

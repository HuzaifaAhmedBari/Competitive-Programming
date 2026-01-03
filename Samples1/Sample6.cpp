#include<stdio.h>
#include<string.h>
int main()
{
	char x[2][1000000];
	scanf("%s", x[0]);
	scanf("%s", x[1]);
	int len;
	len=strlen(x[0]);
	int len1;
	len1 = strlen(x[1]);
	if(x[0][len-1]%2 == 0)
	{
		if(x[1][len1-1]%2==0)
		{
			printf("Black");
		}
		else
			printf("White");
	}
	if(x[0][len-1]%2 != 0)
	{
		if(x[1][len1-1]%2 == 0)
		{
			printf("White");
		}
		else
			printf("Black");
	}
}

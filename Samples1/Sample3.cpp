#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int i,n,j;
	scanf("%d", &n);
	char a[n][101];
	char b[n][101];
	for(i = 0; i<n; i++)
	{
		scanf("%s", &a[i]);
	}
	for(i=0;i<n;i++)
	{
		int len = strlen(a[i]);
		if(len<10)
		{
			strcpy(b[i],a[i]);
		}
		else
		{
			j = len - 2;
			b[i][0] = a[i][0];
			b[i][2] = j%10;
			j/=10;
			b[i][1] = j%10;
			b[i][3] = a[i][len-1];
			b[i][4] = '\0';
		}
	}
	for(i=0;i<n;i++)
	{
		if(isalpha(b[i][1])!= 0)
			printf("%s\n", b[i]);
		else
		{
			printf("%c", b[i][0]);
			printf("%d", b[i][1]);
			printf("%d", b[i][2]);
			printf("%c\n", b[i][3]);
		}
	}
}

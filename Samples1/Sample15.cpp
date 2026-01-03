#include<stdio.h>
int main()
{
	int i,x,a,b;
	int t;
	scanf("%d", &t);
	int fre[t];
	for(i=0;i<t;i++)	fre[i] = 0;
	for(i=0;i<t;i++)
	{
		scanf("%d %d", &x, &a);
		scanf(" %d", &b);
		fre[i] = (a + (100-x)*b) * 10;
	}
	for(i=0;i<t;i++)
	{
		printf("%d", fre[i]);
	}
}

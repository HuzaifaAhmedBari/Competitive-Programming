#include<stdio.h>
int main()
{
	int n,i,temp,max=0;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &temp);
		max+=temp;
	}
	printf("%d", max);
}

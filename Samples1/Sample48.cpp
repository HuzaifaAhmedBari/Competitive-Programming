#include<stdio.h>
int main()
{
	int n,i,j,a,max=-1;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &a);
		if(a>max)
		{
			max = a;
		}
	}
	printf("%d", max);
}

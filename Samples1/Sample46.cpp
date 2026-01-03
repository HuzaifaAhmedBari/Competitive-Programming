#include<stdio.h>
int main()
{
	int n,t,i,count=0,c,j,max=1010;
	scanf("%d %d", &n, &t);
	for(i=0;i<n;i++)
	{
		scanf("%d %d", &c,&j);
		fflush(stdin);
		if(j<=t)
		{
			if(c<max)
			{
				max = c;
				count = max;
			}
		}
	}
	if(count!=0)
	printf("%d",count);
	else
		printf("TLE");
}


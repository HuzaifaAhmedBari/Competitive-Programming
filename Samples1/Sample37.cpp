#include<stdio.h>
int main()
{
	int n, m,m1,i,j,temp;
	scanf("%d %d",&n,&m);
	int found[m];
	for(i=0;i<m;i++)	found[i] = 0;
	for(i=0;i<n;i++)
	{
		scanf("%d", &m1);
		for(j=0;j<m1;j++)
		{
			scanf("%d",&temp);
			found[temp-1]++;
		}
	}
	int count = 0;
	for(i=0;i<m;i++)
	{
		if(found[i] == n)
			count++;
	}
	printf("%d", count);
}

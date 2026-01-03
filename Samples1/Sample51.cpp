#include<stdio.h>
int main()
{
	int n,i,j,max,min,flag = 1,a1=0,a2=0;
	scanf("%d", &n);
	int l[n], u[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d", &l[i], &u[i]);
		if(flag == 1)
		{
			flag = 0;
			min = u[0];
			max = l[0];
		}
		else if(flag == 0)
		{
			if(min > u[i])
				min = u[i];
			if(max < l[i])
				max = l[i];
		}
	}
	for(i=0;i<n;i++)
	{
		if(min - l[i] > 0)
			a1++;
		if(u[i] - max > 0)
			a2++;
	}
	if(a1 == 0 && a2 == 0)
	{
		printf("%d", 1);
		return 0;
	}
	if(a1>a2)
		printf("%d", a1);
	else
		printf("%d", a2);
}

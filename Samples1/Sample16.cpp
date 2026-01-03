#include<stdio.h>
int main()
{
	int t, i;
	scanf("%d", &t);
	if(t%2 == 0)
	{	
		printf("No");
		return 0;
		
	}
	char a[t];
	scanf("%s", &a);
	int b = (t+1)/2 - 2;
	int c = (t+1)/2 - 1;
	int d = (t+1)/2 + 2;
	for(i=0;i<t;i++)
	{
		if(i<=b)
		{
			if(a[i] != '1')
			{
				printf("No");
				return 0;
			}
			
		}
		else if(i==c)
		{
			if(a[i] != '/')
			{
				printf("No");
				return 0;
			}
		}
		else if(i>=d)
		{
			if(a[i] != '2')
			{
				printf("No");
				return 0;
			}
		}
	}
	printf("Yes");
	
	return 0;
}

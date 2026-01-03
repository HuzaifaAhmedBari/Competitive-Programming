#include<stdio.h>
int main()
{
	int a[3][3];
	int c[3][3];
	int i,j,n,b;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j] = 0;
			scanf("%d", &a[i][j]);
		}
	}
	int k;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &b);
		for(j=0;j<3;j++)
		{
			for(k=0; k<3; k++)
			{
				if(b == a[j][k])
				{
					c[j][k] = 1;
				}
			}
		}
	}
	int counter = 0;
	for(i=0; i<3; i++)
	{
		counter = 0;
		for(j=0; j<3; j++)
		{
			if(c[i][j] == 1)
			{
				counter++;
			}
			else
				counter = 0;
			if(counter == 3)
			{
				printf("Yes");
				return 0;
			}
		}
	}
	for(i=0; i<3; i++)
	{
		counter = 0;
		for(j=0; j<3; j++)
		{
			if(c[j][i] == 1)
			{
				counter++;
			}
			else
				counter = 0;
			if(counter == 3)
			{
				printf("Yes");
				return 0;
			}
		}
	}
	if(c[1][1] == 1 && c[2][2] == 1 && c[3][3] == 1)
	{
		printf("Yes");
		return 0;
	}
	if(c[1][3] == 1 && c[2][2] == 1 && c[3][1] == 1)
	{
		printf("Yes");
		return 0;
	}
	printf("No");
	return 0;
}

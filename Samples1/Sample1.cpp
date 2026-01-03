#include<stdio.h>
int main()
{
	int t, i, j, n, x;
	scanf("%d", &t);
	int a[t];
	for(i=0; i<t; i++)
	{
		scanf("%d %d", &n, &x);
		int b[n];
		for(j=0; j<n; j++)
		{
			scanf("%d", &b[j]);
		}
		int counter = n;
		for(j=n-1; j>=0; j--)
		{
			if(x>b[j])
			{
				a[i] = counter;
				break;
			}
			else
				a[i] = 0;
			counter--;
		}
	}
	for(i=0; i<t; i++)
	{
		printf("%d\n", a[i]);
	}
}

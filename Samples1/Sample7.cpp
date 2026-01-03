#include<stdio.h>
int main()
{
	int n, i = 0;
	scanf("%d", &n);
	int j = n-1;
	char a[n];
	for(i=0;i<n;i++)
	{
		a[i] = '\0';
	}
	i=0;
	if(n%2==0)
	{
		while(i<n/2)
		{
			a[i] = 'a' + i;
			a[j] = a[i];
			i++;
			j--;
		}
		a[n] = '\0';
	}
	else
	{
		while(i<=n/2)
		{
			a[i] = 'a' + i;
			a[j] = a[i];
			i++;
			j--;
		}
	}
	printf("%s", a);
	
	return 0;
}

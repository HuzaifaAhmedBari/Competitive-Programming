#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j;
	scanf("%d", &n);
	int f[n];
	char a[n][12];
	for(i=0;i<n;i++)
	{
		scanf("%s", &a[i]);
		f[i] = 0;
	}
	for(i=0;i<n-1;i++)
	{
			for(j=i+1;j<n;j++)
			{
				if(i==j)
					continue;
				if(strcmp(a[i],a[j]) == 0)
				{
					if(j>i)
					{
						f[j]+=f[i]+1;
						break;
					}
				}
			}
	}
	for(i=0;i<n;i++)
	{
		if(f[i] >= 1)
		{
			printf("%s(%d)\n",a[i],f[i]);
		}
		else
			printf("%s\n",a[i]);
	}
}

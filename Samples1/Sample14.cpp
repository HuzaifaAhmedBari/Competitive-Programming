#include<stdio.h>
int main()
{
	int n,m,k,count=0;
	scanf("%d %d %d", &n, &m, &k);
	int a[n], b[n], fre[m+1];
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d %d", &a[i], &b[i]);
	}
	for(i=0;i<m+1;i++)	fre[i] = 0;
	
	for(i=0;i<n;i++)
	{
		fre[a[i]] = b[i];
	}
	for(i=0;i<m+1;i++)
	{
		while(fre[i] != 0 && k != 0)
		{
			k--;
			fre[i]--;
			count++;
		}
	}
	printf("%d", count);
}

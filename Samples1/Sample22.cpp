#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	if(n>2000)
	{
		printf("0");
		return 0;
	}
	int ans=1;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			ans = ans * (arr[i]^arr[j]);
		}
	}
	ans = ans % 998244353;
	printf("%d", ans);
	return 0;
}

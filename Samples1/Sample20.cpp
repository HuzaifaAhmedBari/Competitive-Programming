#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld", &n);
	int arr[n];
	long long int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	long long int ans=1;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			ans = ans * (arr[i]^arr[j]);
		}
	}
	ans = ans % 998244353;
	printf("%d", ans);
}

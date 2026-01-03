#include<stdio.h>
int main()
{
	int sum=0,t,n,i,j,ans=0;
	scanf("%d %d",&n,&t);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
		if(sum>t)
			continue;
		
		ans = i;
	}
	printf("%d",ans+1);
}

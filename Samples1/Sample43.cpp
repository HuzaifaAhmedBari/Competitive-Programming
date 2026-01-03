#include<stdio.h>
int main()
{
	int t,a,b,c,n,i,j;
	scanf("%d",&t);
	int arr[t];
	for(i=0;i<t;i++)
	{
		int sum = 0;
		scanf("%d %d %d %d",&n,&a,&b,&c);
		sum = a+b+c;
		int ans = n/sum;
		if (sum*ans >= n)
			arr[i] = 3*ans;
		else if(sum*ans + a >= n)
			arr[i] = 3*ans+1;
		else if(sum*ans + a + b >= n)
			arr[i] = 3*ans+2;
		else
			arr[i] = 3*ans + 3;
	}
	for(i=0;i<t;i++)
	{
		printf("%d\n",arr[i]);
	}
}

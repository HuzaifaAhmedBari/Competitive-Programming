#include<stdio.h>
int fib(int a)
{
	if(a==1 || a==0)
	{
		return 1;
	}
	return fib(a-1)+fib(a-2);
}
int main()
{
	int n,i,j,sum=0,flag=0;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
		flag = arr[i];
		printf("%d",fib(flag));
	}
	
}

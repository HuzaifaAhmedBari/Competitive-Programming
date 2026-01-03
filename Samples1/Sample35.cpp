#include<stdio.h>
int main()
{
	int i,t;
	long long int a,b;
	scanf("%d", &t);
	long long int arr[t];
	for(i=0;i<t;i++)
	{
		scanf("%lld %lld", &a, &b);
		arr[i] = a+b;
	}
	for(i=0;i<t;i++)
	{
		printf("%lld\n", arr[i]);
	}
}

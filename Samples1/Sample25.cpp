#include<stdio.h>
int main()
{
	long long int t, i, a, b, d;
	scanf("%lld", &t);
	long long int arr[t];
	for(i=0; i<t; i++)
	{
		scanf("%lld", &d);
		arr[i] = (d*(d-1)) / 2;
	}
	for(i=0; i<t; i++)
	{
		printf("%lld\n", arr[i]);
	}
	
	return 0;
}

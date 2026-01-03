#include<stdio.h>
int main()
{
	long long int n,a,b,i,j,sum=0;
	scanf("%lld %lld %lld", &n,&a,&b);
	for(i=0;i<=n;i++)
	{
		if(i%a !=0 && i%b != 0)
			sum+= i;
	}
	printf("%lld", sum);
}

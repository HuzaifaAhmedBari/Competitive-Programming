#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	long long int n, m, s,ans[t];
	int i;
	int j;
	for(j=0;j<t;j++)
	{
		scanf("%lld %lld %lld",&n,&m,&s);
		i=m-1;
		ans[j] = (s + i) % n;
		if(ans[j] == 0)
			ans[j] = n;
	}
	for(i=0;i<t;i++)
	{
		printf("%lld\n", ans[i]);
	}
}

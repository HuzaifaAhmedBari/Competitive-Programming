#include<stdio.h>
int main()
{
	int x,y;
	int i, j, a, b ,ans;
	scanf("%d %d", &x, &y);
	a=x;
	b=y;
	for(i=0;i<a-1;i++)
	{
		x += a;
	}
	for(i=0;i<b-1;i++)
	{
		y += b;
	}
	ans = x + y;
	if(ans%4 == 0)
		printf("%d", ans/4);
	else
		printf("-1");
}

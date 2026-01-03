#include<stdio.h>
int main()
{
	int n1,n2,a,b,c;
	scanf("%d %d",&n1, &n2);
	if(n1< 0 && n2<0 || n1>0 && n2>0)
		printf("%d", n1*n2);
	else if(n2<0)
		printf("%d", n1-n2);
	else
		printf("%d", n1+n2);
}

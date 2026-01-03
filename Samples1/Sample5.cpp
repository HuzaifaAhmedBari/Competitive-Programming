#include<stdio.h>
#include<string.h>
int main()
{
	int i,a,b;
	scanf("%d %d", &a, &b);
	for(i=b;i>0;i--)
	{
		if(a%10 != 0)
			a--;
		else
			a = a/10;
	}
	printf("%d", a);
}

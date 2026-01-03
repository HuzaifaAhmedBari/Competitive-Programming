#include<stdio.h>
int main()
{
	int n,x,y, counter = 0, counter2=0;
	scanf("%d %d %d", &n, &x, &y);
	int a=n;
	while(n!=0)
	{
		if(n<y)
		{
			break;
		}
		else
		{
			n -= y;
			counter += x;
		}
	}
	while(n!=0)
	{
		n--;
		counter++;
	}
	while(a!=0)
	{
		a--;
		counter2++;
	}
	if(counter>counter2)
		printf("%d", counter);
	else
		printf("%d", counter2);
}

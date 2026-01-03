#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int counter = 0, flag = 0;
	int i, j, a, b, c;
	for(i=0;i<n;i++)
	{
		counter = 0;
		scanf("%d %d %d", &a, &b, &c);
		if(a==1)
			counter++;
		if(b==1)
			counter++;
		if(c==1)
			counter++;
		if(counter>=2)
			flag++;
	}
	printf("%d", flag);
}

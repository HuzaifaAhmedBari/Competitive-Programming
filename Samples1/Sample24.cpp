#include<stdio.h>
int main()
{
	int t, i, n, d, a, b;
	scanf("%d", &t);
	int arr[t];
	for(i=0;i<t;i++)
	{
		arr[i] = 0;
		scanf("%d %d", &n, &d);
		a = d*3;
		arr[i] = n/a;
	}
	for(i=0; i<t; i++)
	{
		printf("%d\n", arr[i]);
	}
	
	return 0;
}

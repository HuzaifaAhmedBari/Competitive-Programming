#include<stdio.h>
int main()
{
	int t,i,j;
	int a1,b1,c1,a2,b2,c2;
	scanf("%d", &t);
	int arr[t];
	for(i=0;i<t;i++)
	{
		arr[i] = 0;
		scanf("%d %d %d", &a1, &b1, &c1);
		scanf("%d %d %d", &a2, &b2, &c2);
		int count1=0;
		int count2=0;
		if(a1>a2)
			count1++;
		else
			count2++;
		if(b1>b2)
			count1++;
		else
			count2++;
		if(c1>c2)
			count1++;
		else
			count2++;
		if(count1>count2)
			arr[i] = 1;
		else 
			arr[i] = 2;
	}
	for(i=0;i<t;i++)
	{
		if(arr[i] == 1)
			printf("A\n");
		else 	printf("B\n");
	}
}

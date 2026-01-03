#include<stdio.h>
int main()
{
	int t;
	int i, count=0;
	scanf("%d", &t);
	int arr[t];
	for(i=0;i<t;i++)
	{
		scanf("%d", &arr[i]);
	}
	for(i=t-1;i>0;i--)
	{
		while(arr[i-1] >= arr[i])
		{
			arr[i-1]--;
			count++;
		}
	}
	printf("%d", count);
}

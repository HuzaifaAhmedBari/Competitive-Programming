#include<stdio.h>
int main()
{
	int n;
	int i;
	scanf("%d", &n);
	n *= 4;
	int arr[n-1];
	int fre[n/4 + 1];
	for(i=0;i<n/4;i++)	fre[i] = 0;
	for(i=0;i<n-1;i++)
	{
		scanf("%d", &arr[i]);
	}
	for(i=0; i<n-1; i++)
	{
		fre[arr[i]]++;
	}
	for(i=1; i<n/4; i++)
	{
		if(fre[i] != 4)
			break;
	}
	printf("%d", i);
	
	return 0;
}

#include<stdio.h>
#include<limits.h>
int main()
{
	int t,i,j,min=INT_MAX,count=0,flag;
	scanf("%d", &t);
	int arr[t];
	for(i=0;i<t;i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i]<min)
			min=arr[i];
	}
	for(i=1;i<=min;i++)
	{
		flag=0;
		for(j=0;j<t;j++)
		{
			if(arr[j]%i!=0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			count++;
	}
	printf("%d", count);
}

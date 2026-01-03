#include<stdio.h>
int main()
{
	int n,i,q;
	scanf("%d", &n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &q);
	int arr2[q];
	for(i=0;i<q;i++)
	{
		scanf("%d", &arr2[i]);
	}
	int min,max,j;
	for(i=0;i<q;i++)
	{
		min=-1;
		max=-1;
		for(j=0;j<n;j++)
		{
			if(arr2[i] > arr[j])
			{
				if(min==-1)
					min = arr[j];
				else if(arr[j] > min)
					min = arr[j];
			}
			if(arr2[i] < arr[j])
			{
				if(max==-1)
					max = arr[j];
				else if(arr[j] < max)
					max = arr[j];
			}
		}
		if(min != -1)
		{
			printf("%d ",min);
		}
		else
			printf("X ");
		if(max != -1)
		{
			printf("%d\n",max);
		}
		else
			printf("X\n");
		
	}
}

#include<iostream>
using namespace std;
int main()
{
	int i,j,n,k,x,flag=0,count,found;
	cin>>n;
	int arr[n];
	int ans[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<n;i++)
	{
		count=0;
		flag = 0;
		found=1;
		if(arr[i]%2==0)
		{
			x=arr[i]-1;
		}
		else
			x=arr[i];
		for(j=x;j>=3;j-=2)
		{
			flag=0;
			for(k=3;k<j;k++)
			{
				if(j%k == 0)
				{
					flag = 1;
					break;
				}
			}
			if(flag==0)
			{
				found = j;
				break;
			}
		}
		if(flag==0)
		{
			count++;
			arr[i]-=found;
		}
		int sum=1;
		while(1)
		{
			if(arr[i] == sum)
			{
				count++;
				break;
			}
			else if(sum>arr[i])
				break;
			else
			{
				arr[i]-=sum;
				count++;
				sum*=2;
			}
		}
		if(arr[i] == sum)
		{
			ans[i] = count;
		}
		else
		{
			ans[i] = -1;
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<ans[i]<<endl;
	}
}

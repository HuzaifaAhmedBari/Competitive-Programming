#include<iostream>
using namespace std;
int main()
{
	int t,i,j,n,max,total;
	cin>>t;
	int ans[t];
	for(i=0;i<t;i++)
	{
		max=-1;
		total=0;
		cin>>n;
		int arr[n];
		int fre[n+1] = {0};
		for(j=0;j<n;j++)
		{
			cin>>arr[j];
			fre[arr[j]]++;
		}
		int found=0;
		for(j=0;j<n;j++)
		{
			if(fre[j]>max)
			{
				found=j;
				max=fre[j];
			}
		}
		for(j=0;j<n+1;j++)
		{
			if(j==found)
				continue;
			else if(fre[j]!=0)
				total++;
		}
		if(total>=max)
			ans[i] = max;
		else if(total==0)
			ans[i] = 0;
		else if(max==0)
			ans[i] = 0;
		else if(max==1 && total>=1)
			ans[i] = 1;
		else
		{
			while(max>total)
			{
				max--;
				total++;
			}
			ans[i]=max;
		}
		cout<<ans[i]<<endl;
	}
}

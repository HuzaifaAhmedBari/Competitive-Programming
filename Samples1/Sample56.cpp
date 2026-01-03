#include<iostream>
using namespace std;
int main()
{
	int n,m,k,i,j,x,flag=0,flag2=1;
	cin>>n>>m>>k;
	int box[n];
	int count=0;
	for(i=0;i<n;i++)
	{
		cin>>box[i];
	}
	for(i=0;i<m;i++)
	{
		flag2=1;
		if(flag==0)
		{
			x=n-1;
		}
		int rn = k;
		for(j=x;j>=0;j--)
		{
			flag=1;
			if(box[j]<=rn)
			{
				rn-=box[j];
				count++;
				flag2=0;
			}
			else if(flag2 == 0)
			{
				x=j-1;
				break;
			}
			else
			{
				continue;
			}
		}
	}
	cout<<count;
}

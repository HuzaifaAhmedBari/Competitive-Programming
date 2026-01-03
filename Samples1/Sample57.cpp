#include<iostream>
using namespace std;
int main()
{
	int i,count=1,n,x,y,max=0,flag=0;
	cin>>n;
	cin>>x>>y;
	int a=x;
	max+=x;
	while(x>0)
	{
		if(max+max>=n)
		{
			flag = 1;
			break;
		}
		else
		{
			x-=y;
			max+=x;
			count++;
		}
	}
	(flag==1)? cout<<count : cout<<"RIP";
}

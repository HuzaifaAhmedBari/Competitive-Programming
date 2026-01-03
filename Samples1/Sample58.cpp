#include<iostream>
using namespace std;
int main()
{
	int i,n,x;
	cin>>n>>x;
	int fre[n];
	for(i=0;i<n;i++)
	{
		fre[i]=1;
	}
	int temp;
	for(i=0;i<x;i++)
	{
		cin>>temp;
		fre[temp-1] = (fre[temp-1] == 1) ? 0 : 1;
	}
	int max=0;
	for(i=0;i<n;i++)
	{
		max+=fre[i];
	}
	cout<<max;
}

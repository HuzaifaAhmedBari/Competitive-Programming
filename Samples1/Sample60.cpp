#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double p,temp=0,max=0;
	int i,j,n;
	cin>>n>>p;
	double arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	if(n%2==0)
	{
		for(i=0,j=n-1;i<n;i++,j--)
		{
			temp=0;
			temp = arr[i] + arr[j];
			temp-=(temp)*(p/100);
			max+=temp;
		}	
	}
	cout<<max;
	
}

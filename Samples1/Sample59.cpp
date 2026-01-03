#include<iostream>
using namespace std;
int main()
{
	int t,i,n,j,k,m=0;
	cin>>t;
	int fre[t];
	int ans[1000];
	for(i=0;i<t;i++)
	{
		cin>>n;
		fre[i] = n;
		int arr[n];
		int found[n];
		for(j=0;j<n;j++)
		{
			cin>>arr[i];
			found[i] = (found[i] == 1)? 1:0;
			found[arr[i]] = 1;
		}
		for(j=0;j<n;j++)
		{
			if(found[arr[i]] == 1)
			{
				for(k=0;k<n;k++)
				{
					if(found[k] = 0)
					{
						ans[m] = k;
						m++;
						found[k] = 1;
					}
				}
				continue;
			}
			ans[m] = arr[i];
			m++;
		}
	}
	m=0;
	for(i=0;i<t;i++)
	{
		for(j=0;j<fre[i];j++)
		{
			cout<<ans[m];
			m++;
		}
		cout<<endl;
	}
}

#include<iostream>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	string s[n];
	string t[n];
	for(i=0;i<n;i++)
	{
		cin>>s[i];
		cin>>t[i];
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i] == s[j] && t[i] == t[j])
			{
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
}

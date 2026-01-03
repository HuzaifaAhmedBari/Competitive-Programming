#include<iostream>
using namespace std;
int main()
{
	int n,m,k,i,j,count=0;
	cin>>n;
	cin>>m;
	cin>>k;
	int box[n];
	int fre[n];
	int found[m];
	for(i=0;i<n;i++)
	{
		cin>>box[i];
		fre[i] = 1;
		found[i] = 0;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			int rn=m;
			if(box[j]<=rn)
			{
				rn-=box[j];
				found[i]++;
				fre[j] = 0;
			}
			else
				continue;
		}
		if(i==m-1 && fre[n-1] == 1)
			i==0;
	}
}

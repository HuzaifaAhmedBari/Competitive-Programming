#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,t,n,q,l,u,k,o,m=0,a;
	int ans[50001];
	scanf("%d", &t);
	int fre[t];
	for(i=0;i<t;i++)
	{
		scanf("%d %d", &n, &q);
		fre[i] = q;
		int arr[n];
		for(j=0;j<n;j++)
		{
			scanf("%d", &arr[j]);
		}
		for(o=0;o<q;o++)
		{
			scanf("%d %d", &l, &u);
			int max = 1001;
			for(k=l;k<u;k++)
			{
				for(a=k;a<u;a++)
				{
					int ans = arr[a+1]-arr[k];
					if(abs(ans) < max)
					{
						max = abs(ans);
					}
					max = abs(max);
				}
			}
			ans[m] = max;
			m++;
		}
	}
	m=0;
	for(i=0;i<t;i++)
	{
		printf("Case %d:\n",i+1);
		for(j=0;j<fre[i];j++)
		{
			printf("%d\n", abs(ans[m]));
			m++;
		}
	}
}

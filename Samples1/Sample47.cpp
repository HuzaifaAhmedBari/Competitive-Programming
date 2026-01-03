#include<stdio.h>
int main()
{
	int t,i=0,flag=1;
	scanf("%d", &t);
	while(flag == 1)
	{
		i++;
		int ans = t&(t+1);
		if(ans == 0)
		{
			flag = 0;
			break;
		}
		++t;
		ans = t&(t+1);
		if(ans == 0)
		{
			i++;
			flag = 0;
			break;
		}
			
	}
	printf("%d", i);
}

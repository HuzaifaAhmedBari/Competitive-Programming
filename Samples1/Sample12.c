#include<stdio.h>
#include<string.h>
int main()
{
	char s[101];
	int len, i, j;
	int flag = 0;
	char *ptr;
	scanf("%s", s);
	len=strlen(s);
	if(len<5)
	{
		printf("NO");
		return 0;
	}
	ptr = strchr(s, 'h');
	if(ptr == NULL)
	{
		printf("NO");
		return 0;
	}
	len = strlen(ptr);
	for(i=1; i<len; i++)
	{
		if(*(ptr+i) == 'e')
		{
			flag=1;
			break;
		}
	}
	ptr = strchr(ptr, 'e');
	if(ptr == NULL)
	{
		printf("NO");
		return 0;
	}
	len = strlen(ptr);
	
	if(flag == 0)
	{
		printf("NO");
		return 0;
	}
	
	flag= 0;
	for(i=1; i<len; i++)
	{
		if(*(ptr+i) == 'l')
		{
			flag=1;
			break;
		}
		
	}
	ptr = strchr(ptr, 'l');
	if(ptr == NULL)
	{
		printf("NO");
		return 0;
	}
	len = strlen(ptr);
	
	if(flag == 0)
	{
		printf("NO");
		return 0;
	}
	flag= 0;
	for(i=1; i<len; i++)
	{
		if(*(ptr+i) == 'l')
		{
			flag=1;
			break;
		}
	}
	ptr = strchr(ptr, 'l');
	if(ptr == NULL)
	{
		printf("NO");
		return 0;
	}
	len = strlen(ptr);
	if(flag == 0)
	{
		printf("NO");
		return 0;
	}
	flag= 0;
	for(i=1; i<len; i++)
	{
		if(*(ptr+i) == 'o')
		{
			flag=1;
			break;
		}
	}
	
	if(flag == 0)
	{
		printf("NO");
		return 0;
	}
	printf("YES");
	
	return 0;
}

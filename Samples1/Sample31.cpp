#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *rev(char *str, int start, int end)
{
	static char *temp;
	temp = (char *)realloc(temp, sizeof(char));
	if(end < 0)
	{
		return temp;
	}
	temp[start] = str[end];
	rev(str, start+1, end-1);
}
int main()
{
	char str[2001];
	printf("Enter a String : ");
	fgets(str, 2000, stdin);
	str[strcspn(str, "\n")] = '\0';
	int len = strlen(str);
	char *pos = rev(str, 0, len-1);
	printf("\nReversed String : %s", pos);
}

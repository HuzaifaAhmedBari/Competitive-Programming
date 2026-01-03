#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *concat(char *dest, char *src, int j, int i)
{
	static int k = 0;
	dest = (char *)realloc(dest, sizeof(char));
	if(k == i)
	{
		dest[j] = '\0';
		return dest;
	}
	dest[j] = src[k];
	k++;
	concat(dest, src, j+1, i);
	
}
int main()
{
	int n1, n2;
	printf("Enter the Size of the First String : ");
	scanf("%d", &n1);
	printf("Enter the Size of the Second String : ");
	scanf("%d", &n2);
	char *dest = (char *)calloc(n1+1, sizeof(char));
	char *src = (char *)calloc(n2+1, sizeof(char));
	scanf("%s", dest);
	scanf("%s", src);
	int len = strlen(src);
	int len1 = strlen(dest);
	
	
	printf("ANS:%s",concat(dest, src, len1, len));
}

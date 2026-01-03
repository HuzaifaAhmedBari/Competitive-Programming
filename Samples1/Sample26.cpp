#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	int n, i;
	scanf("%d", &n);
	char arr[n+1];
	int found[26];
	scanf("%s", arr);
	for(i=0; i<n; i++)
	{
		arr[i] = tolower(arr[i]);
		found[arr[i] - 'a'] = 1;
	}
	if(n<26)
	{
		printf("NO");
		return 0;
	}
	for(i=0; i<26; i++)
	{
		if(found[i] == 0)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}

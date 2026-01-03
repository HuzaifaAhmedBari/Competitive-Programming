#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main()
{
	int i,j=0;
	char *result;
	result = (char *)malloc(sizeof(char));
	char arr[201];
	do
	{
		fgets(arr, 201, stdin);
		arr[strcspn(arr,"\n")] = '\0';
		if(strcmp(arr,"ENDOFINPUT") == 0)
		{
			break;
		}
		fgets(arr, 201, stdin);
		int len = strlen(arr);
		for(i=0;i<len;i++)
		{
			result = (char *)realloc(result, len*sizeof(char));
			if(arr[i] == 'V')	result[j] = 'A';
			else if(arr[i] == 'W')	result[j] = 'B';
			else if(arr[i] == 'Y')	result[j] = 'C';
			else if(arr[i] == 'X')	result[j] = 'D';
			else if(arr[i] == 'Z')	result[j] = 'E';
			else if (isalpha(arr[i]))	result[j] = arr[i] + 5;
			else	result[j] = '\n';
			j++;
		}
		fgets(arr, 201, stdin);
		
	}while(1);
	fflush(stdin);
	fflush(stdout);
	printf("AV");
	result = (char *)realloc(result, 1*sizeof(char));
	result[j] = '\0';
	printf("HE");
	printf("%s", result);
	
	return 0;
}

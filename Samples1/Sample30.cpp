#include<stdio.h>
#include<string.h>

char* reversestring(char *string, int l)
{
    if(l == 0)
    {
        printf("%c", string[l]);
        
    }
    else
    {
        printf("%c", string[l]);
        l = l - 1;
        reversestring(string, l);
    }
}

int main()
{
    char string[50];
    printf("enter the sentence:");
    scanf("%s", string);
    int l = strlen(string);
    reversestring(string, l);
}


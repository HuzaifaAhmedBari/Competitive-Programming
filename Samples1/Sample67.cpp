#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,t,sum1=0,sum2=0;
    char arr[250];
    scanf("%s", arr);
    for(i=0;i<strlen(arr)-1;i++)
    {
        if(arr[i] == 'A')
        {
            if(arr[i+1] == '1')
                sum1+=1;
            else
                sum1+=2;
        }
        else if(arr[i] == 'B')
        {
            if(arr[i+1] == '1')
                sum2+=1;
            else
                sum2+=2;
        }
        i++;
    }
    if(sum1>sum2)
        printf("A");
    else   
        printf("B");
}
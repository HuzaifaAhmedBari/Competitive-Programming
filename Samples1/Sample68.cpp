#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int t,i,j=1,count=0,m=0;
    char arr[6];
    int ans[t];
    scanf("%d", &t);
    while(t--)
    {
        count=0;
        scanf("%s", arr);
        for(i=0;i<4;i++)
        {
            if(arr[i] == '1')
            {
                count += abs(j-1)+1;
                j=1;
            }
            else if(arr[i] == '2')
            {
                count += abs(j-2)+1;
                j=2;
            }
            else if(arr[i] == '3')
            {
                count += abs(j-3)+1;
                j=3;
            }
            else if(arr[i] == '4')
            {
                count += abs(j-4)+1;
                j=4;
            }
            else if(arr[i] == '5')
            {
                count += abs(j-5)+1;
                j=5;
            }
            else if(arr[i] == '6')
            {
                count += abs(j-6)+1;
                j=6;
            }
            else if(arr[i] == '7')
            {
                count += abs(j-7)+1;
                j=7;
            }
            else if(arr[i] == '8')
            {
                count += abs(j-8)+1;
                j=8;
            }
            else if(arr[i] == '9')
            {
                count += abs(j-9)+1;
                j=9;
            }
            else if(arr[i] == '0')
            {
                count += abs(j-10)+1;
                j=10;
            }
        }
        ans[m] = count;
        m++;
    }
    for(i=0;i<t;i++)
    {
        printf("%d\n", ans[i]);
    }
}
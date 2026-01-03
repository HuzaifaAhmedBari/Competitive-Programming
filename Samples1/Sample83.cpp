#include<stdio.h>
#include<string.h>
int main()
{
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int t;
    scanf("%d", &t);
    char temp[t][12], code[t][3], start[t][3];
    int ans = 0;
    for(int i=0;i<t;i++)
    {
        scanf("%s %s", temp[i], code[i]);
        start[i][0] = temp[i][0];
        start[i][1] = temp[i][1];
        start[i][2] = '\0';
    }
    for(int i=0;i<t-1;i++)
    {
        for(int j=i+1;j<t;j++)
        {
            if(strcmp(start[i],code[j]) == 0)
            {
                if(strcmp(code[i],start[j]) == 0 && strcmp(code[i],code[j]) != 0)
                {
                    ans++;
                }
            }
        }
    }
    printf("%d", ans);
}
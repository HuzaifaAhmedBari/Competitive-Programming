#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hamming.in","r",stdin);
    int i,j,t,s,count1=0,count2=0,count3=0,count4=0,total=0;
    cin>>t;
    int ans[t] = {0};
    for(i=0;i<t;i++)
    {
        count1=0,count2=0,count3=0,count4=0;
        cin>>s;
        total=s;
        char a[s],b[s];
        cin>>a>>b;
        for(j=0;j<s;j++)
        {
            if(a[j] == '1')
                count1++;
            else
                count2++;
            if(b[j] == '1')
                count3++;
            else
                count4++;
        }
        if(count1>count2)
        {
            if(count1>count4)
            {
                ans[i] += count4;
                s-=count4;
            }
            else if(count4>=count1)
            {
                ans[i] += count1;
                s-=count1;
            }
            if(s>0 && count2 > count3)
            {
                if(s>=count3)
                {
                    ans[i]+=count3;
                }
                else
                {
                    ans[i] = s;
                }
            }
            else if(s>0 && count3>=count2)
            {
                if(s>=count2)
                {
                    ans[i]+=count2;
                }
                else
                {
                    ans[i] = s;
                }
            }
        }
        else
        {
            if(count2>count3)
            {
                ans[i] += count3;
                s-=count3;
            }
            else if(count3>=count2)
            {
                ans[i] += count2;
                s-=count2;
            }
            if(s>0 && count1 > count4)
            {
                if(s>=count4)
                {
                    ans[i]+=count4;
                }
                else
                {
                    ans[i] = s;
                }
            }
            else if(s>0 && count4>=count1)
            {
                if(s>=count1)
                {
                    ans[i]+=count1;
                }
                else
                {
                    ans[i] = s;
                }
            }
        }
    }
    for(i=0;i<t;i++)
    {
        cout<<ans[i]<<endl;
    }
    
}
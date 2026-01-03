#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t,s1,s2,t1,t2,k;
    int low,high;
    cin>>t;
    int flag,ans=0;
    while(t--)
    {
        ans=0;
        flag=1;
        cin>>s1>>s2>>t1>>t2>>k;
        s1 = abs(t1-s1);
        s2 = abs(t2-s2);
        low = (s1<s2)? s1 : s2;
        high = (s1<s2)? s2 : s1;
        if(k>low)
        {
            ans+=low;
            if(k*2>=high)
            {
                ans+=high;
                
            }
            else
            {
                ans+=k*2;
                high -= k*2;
                // ans+=high;
                int temp = high/k;
                ans+=k*temp;
                high-=k*temp;
                
                //ans += 2 * temp;
                if(high>=k)
                {
                    ans+=high;
                    //ans++;
                }
                if(temp%2==1)
                    ans++;
                // high *= temp;
                // ans+=high - k;
            }
        }
        else
        {
            ans += low;
            int temp=low/k;
            if(k*temp>high)
            {
                ans+=high;
                high=0;
            }
            else
            {
                ans+=k*temp;
                high-=k*temp;
                if(high-k>0)
                {
                    ans+=k;
                    high-=k;
                    //high=0;
                }
                else if(k-high>0)
                {
                    ans+=high;
                    high=0;
                }
                int temps = high/k;
                ans+= temps;
                high-=k*temps;
                if(k*temps<high)
                {
                    ans+=high-k*temps;
                }
                cout<<temps<<endl;
                if(temps%2==1)
                {
                    ans++;
                }
                if(high>0)
                {
                    ans+=high;
                    ans++;
                }
                //ans += 2 * temp;
                    // high *= temp;
                    // ans+=high - k;
            }
        }
        cout<<ans<<endl;
        // while(low!=0)
        // {
        //     if(flag)
        //     {
        //         if(high-k<0)
        //         {
        //             ans+=high;
        //             high=0;
        //         }
        //         else
        //         {
        //             ans+=k;
        //             high-=k;
        //         }
        //     }
        //     else
        //     {
        //         if(low-k<0)
        //         {
        //             ans+=low;
        //             low=0;
        //         }
        //         else
        //         {
        //             ans+=k;
        //             low-=k;
        //         }
        //     }
        //     flag = (flag)? 0:1;
        // }
        // flag=0;
        // if(high-k<0)
        // {
        //     ans+=high;
        //     high=0;
        // }
        // else
        // {
        //     ans+=k;
        //     high-=k;
        // }
        // int flag2=0;
        // int count=0;
        // while(high!=0)
        // {
        //     count++;
        //         if(high-k<=0)
        //         {
        //             ans+=high;
        //             high=0;
        //             ans += (flag2)? 1:2;
        //         }
        //         else
        //         {
        //             ans+=k;
        //             high-=k;
        //             ans++;
        //             flag2 = (flag2)? 0:1;
        //         }
        // }
        // count/=2;
        // cout<<ans-count<<endl;
    }
}
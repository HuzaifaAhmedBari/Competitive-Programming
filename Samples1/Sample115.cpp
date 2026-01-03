#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int ans=n*m;
    int who=1;
    // if(m==1 || n==1)
    // {
    //     cout<<"Akshat"<<endl;
    // }
    // if(n==m)
    // {
    //     (n%2==0)? cout<<"Malvika"<<endl : cout<<"Akshat"<<endl;
    // }
    // else if(n%2==0)
    // {
    //     if(n%4==0 && m%2==1)
    //     {
    //         cout<<"Akshat"<<endl;
    //     }
    //     else if(n%2==0 && m%2==1)
    //     {
    //         cout<<"Malvika"<<endl;
    //     }
    //     else
    //     {
    //         cout<<"Malvika"<<endl;
    //     }

    // }
    // else if(m%2==0)
    // {
    //     if(m%4==0 && n%2==1)
    //     {
    //         cout<<"Akshat"<<endl;
    //     }
    //     else if(m%2==0 && n%2==1)
    //     {
    //         cout<<"Malvika"<<endl;
    //     }
    //     else{
    //         cout<<"Malvika"<<endl;
    //     }
    // }
    int i=0;
    int flag;
    if(ans%2==0){
        ans = ans/2+1;
        who = (who)? 0:1;
        flag=1;
    }
    else if(ans%4==0)
        {
            ans= ans/2+2;
            flag=2;
        who = (who)? 0:1;
        }
    while(1)
    {
        i++;
        if(flag==1){
            
            if(ans-1 == 1)
                break;
            ans = ans/2+1;
            who = (who)? 0:1;
            if(ans-1 == 1)
                break;
        }
        else if(flag==2)
        {
            
        if(ans-2 == 1)
        break;
            ans= ans/2+2;
            
        who = (who)? 0:1;
        if(ans-2 == 1)
            break;
        }
    }
    (who)? cout<<"Malvika"<<endl : cout<<"Akshat"<<endl;
    // if(n%2==0 || m%2==0)
    //     cout<<"Malvika"<<endl;
    // else   
    //     cout<<"Akshat"<<endl;
}
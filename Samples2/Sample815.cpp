//Maqsad Nahi Bhoolna
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long t = 1;
    // cin>>t;
    for(long long k=1;k<=t;k++)
    {
        long long a,b;
        cin>>b>>a;
        if(a%b!=0)
        {
            cout<<0<<endl;
            continue;
        }
        a/=b;
        long long ans=0;
        for(long long i=2;i*i<=a;i++)
        {
            if(a%i==0)
            {
                ans++;
                while(a%i==0)
                {
                    a/=i;
                }
            }
        }
        cout<<(1LL<<((a>1)?ans+1:ans));
        cout<<endl;
    }
    return 0;
}
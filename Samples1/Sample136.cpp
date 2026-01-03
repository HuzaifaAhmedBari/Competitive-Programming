#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int a,b;
    int t;
    cin>>t;
    long long int d= (1e9)+7;
    while(t--)
    {
        cin>>a>>b;
        if(a==0 && b==0)
        {
            cout<<1<<endl;
            continue;
        }
        else if(a==0 && b!=0)
        {
            cout<<0<<endl;
            continue;
        }
        long long ans=a;
        for(int i=1;i<b;i++)
        {
            a = (a*ans)%d;
        }
        cout<<a<<endl;
    }
}
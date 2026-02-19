#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cout<<"Case "<<k<<": ";
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(((a+b)&1)!=((d+c)&1))
        {
            cout<<"impossible"<<endl;
            continue;
        }
        if(a==c and b==d)
        {
            cout<<0<<endl;
            continue;
        }
        if(abs(a-c)==abs(b-d))
        {
            cout<<1;
        }
        else
        {
            cout<<2;
        }
        cout<<endl;
    }
}
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    while(n!=0)
    {
        int i;
        ans = n;
        for(i=0;i<n;i+=3)
        {
            ans=0;
        }
        if(n==1)
            cout<<0<<endl;
        if(i>n)
        {
            cout<<i/3<<endl;
        }
        else
        {
            cout<<i/3<<endl;
        }
        cin>>n;
    }

}
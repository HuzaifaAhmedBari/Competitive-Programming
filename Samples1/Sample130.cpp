#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    long long int d = (pow(10,9)+7LL);
    cin>>t;
    long long int a,b,c;
    while(t--)
    {
        cin>>a>>b>>c;
        if(a==0 || b==0 || c==0)
        {
            cout<<0<<endl;
            continue;
        }
        long long int ans = pow(pow(a,b),c);
        cout<<ans%d<<endl;
    }
}
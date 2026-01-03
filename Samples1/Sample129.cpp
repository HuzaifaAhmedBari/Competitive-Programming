#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int a,b;
    long long int sum=1;
    while(t--)
    {
        cin>>a>>b;
        sum*=pow(a,b);
    }
    long long int ans1=0;
    int count=1;
    long long int ans2=1;
    for(long long int i=sum-1;i>=1;i--)
    {
        if(sum%i==0)
        {
            count++;
            ans1+=i;
            ans2*=i;
        }
    }
    long long int d = 10e9+7;
    cout<<count%d<<' '<<(ans1+sum)%d<<' '<<(ans2*sum)%d<<endl;
}
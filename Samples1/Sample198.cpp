//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<endl
#define re return 0
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int t = 1;
    cin>>t;
    ll a,b;
    bool flag=false;
    ll sum1=0,sum2=0;
    while(t--)
    {
        cin>>a>>b;
        if(a%2)
        {
            sum1++;
        }
        if(b%2)
        {
            sum2++;
        }
        if(a%2 && b%2)
        {
            sum1--;
            sum2--;
            flag=!flag;
        }
    }
    if(flag && sum1==0 && sum2==0)
    {
        cout<<-1;
        nl;
    }  
    else if(sum1%2==0 && sum2%2==0)
    {
        cout<<0;
        nl;
    }
    else if((sum1%2==1 && sum2%2==0) || (sum2%2==1 && sum1%2==0))
    {
        cout<<-1;
        nl;
    }
    else if(sum1>0 || sum2>0)
    {
        cout<<1;
        nl;
    }
    return 0;
}
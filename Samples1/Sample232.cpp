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
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define yesno(expr) (expr)? cout<<"Yes" : cout<<"No"
#define Yesno(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int t = 1;
    cin>>t;
    int n=t;
    bool give = false;
    ll sum1=0,sum2=0;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        sum1+=a;sum2+=b;
        if(!give)
            give = ((a&1) != (b&1))? true : false;
    }
    if(n==1)    give=false;
    if((sum1&1) == (sum2&1))
    {
        if(sum1&1)
        {
            if(give)    cout<<1;
            else    cout<<-1;
        }
        else
            cout<<0;
    }
    else
    {
        cout<<-1;
    }
    nl;
    return 0;
}
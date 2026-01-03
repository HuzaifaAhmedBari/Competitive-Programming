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
    while(t--)
    {
        ll a;
        cin>>a;
        ll temp = a/15;
        ll ans = temp;
        ans+=1;
        if(temp*15+2<=a)
        {
            ans+=temp*2;
        }
        else if(temp*15+1<=a)
        {
            ans+=temp*2 - 1;
        }
        else
        {
            ans+=temp*2 - 2;
        }
        if(2<=a)
        {
            ans+=2;
        }
        else if(1<=a)
        {
            ans++;
        }
        if(a==0)
        {
            cout<<1;
            nl;
            continue;
        }
        else if(a==1)
        {
            cout<<2;
            nl;
            continue;
        }
        cout<<ans;
        nl;
    }
    return 0;
}
//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<"\n"
#define re return 0
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define us unordered_set<ll>
#define all(vec) vec.begin(), vec.end()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(ll i=a;i<b;i++)
#define forj(a,b) for(ll j=a;j<b;j++)
#define fork(a,b) for(ll k=a;k<b;k++)
#define forr(a,b) for(ll r=a;r>=b;r--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    string a;
    cin>>a;
    string b;
    if(a[0]=='@' || a[a.size()-1]=='@')
    {
        cout<<"No solution";
        nl;
        re;
    }
    ll count=0;
    ll j;
    fori(0,a.size())
    {
        if(a[i]=='@')
        {
            count++;
        }
    }
    fori(0,a.size())
    {
        if(a[i]!='@')
        {
            b+=a[i];
        }
        else
        {
            j=i;
            break;
        }
    }
    bool flag=true;
    fori(j,a.size())
    {
        if(a[i]=='@' && (a[i-2]=='@' || a[i-1] == '@'))
        {
            flag=false;
        }
        else
        {
            b+=a[i];
        }
        if(a[i-1]=='@' && count>1)
        {
            count--;
            b+=',';
        }
    }
    if(count==0)
        flag=false;
    if(flag)
    {
        cout<<b;
    }
    else
        cout<<"No solution";
    nl;
    return 0;
}
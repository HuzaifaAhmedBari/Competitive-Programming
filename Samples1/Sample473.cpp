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
#define input(vec) fork(0,vec.size()) cin>>vec[k]
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
bool ispalindrome(string a)
{
    for(ll i=0,j=a.size()-1;i<a.size()/2;i++,j--)
    {
        if(a[i]!=a[j])
            return false;
    }
    return true;
}
int main()
{
    io;
    ll n,k;
    cin>>n>>k;
    string a;
    cin>>a;
    if(ispalindrome(a))
    {
        cout<<a;
        string b;
        fori(a.size()/2,a.size())
        {
            b+=a[i];
        }
        fori(0,k-1)
        {
            cout<<b;
        }
    }
    else
    {
        fori(0,k)
        {
            cout<<a;
        }
    }
    nl;
    return 0;
}
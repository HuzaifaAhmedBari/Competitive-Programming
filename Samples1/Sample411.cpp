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
    int t = 1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vl arr(n);
        input(arr);
        if(is_sorted(all(arr)))
        {
            cout<<0;
            nl;
            continue;
        }
        vl a = arr;
        sort(arr.begin()+1,arr.end());
        sort(a.begin(),a.end()-1);
        if(is_sorted(all(arr)) || is_sorted(all(a)))
        {
            cout<<1;
            nl;
            continue;
        }
        sort(arr.begin(),arr.end()-1);
        sort(a.begin()+1,a.end());
        if(is_sorted(all(arr)) || is_sorted(all(a)))
        {
            cout<<2;
            nl;
        }
        else
        {
            cout<<3;
            nl;
        }
    }
    return 0;
}
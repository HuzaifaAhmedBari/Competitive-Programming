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
        int n,m,q;
        cin>>n>>m>>q;
        vl arr(m);
        ll temp;
        input(arr);
        sahi(arr);
        while(q--)
        {
            int a;
            cin>>a;
            if(binary_search(all(arr),a))
            {
                cout<<0;
                nl;
                continue;
            }
            auto it1 = upper_bound(all(arr),a);
            if(it1==arr.begin())
            {
                cout<<*it1-1;
                nl;
                continue;
            }
            else if(it1==arr.end())
            {
                cout<<n-arr.back();
                nl;
                continue;
            }
            auto it2 = it1-1;
            cout<<(*it1-a+a-*it2)/2;
            nl;
        }
    }
    return 0;
}
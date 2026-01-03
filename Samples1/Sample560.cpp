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
int main()
{
    io;
    ll n,m;
    cin>>n>>m;
    vl arr(n);
    input(arr);
    ll l=0,r=n-1;
    vl ans=arr;
    sahi(arr);
    while(l<r)
    {
        if(arr[l]+arr[r]==m)
        {
            ll more=0;
            auto it1 = find(all(ans),arr[l]);
            ll dl = distance(ans.begin(),it1)+1;
            ll dr;
            if(arr[l]==arr[r])
                dr = distance(ans.begin(),find(ans.begin()+dl,ans.end(),arr[r]))+1;
            else
            {
                auto it2 = find(all(ans),arr[r]);
                dr = distance(ans.begin(),it2)+1;
            }
            cout<<min(dl,dr)<<" "<<max(dl,dr);
            nl;
            re;
        }
        else if(arr[l]+arr[r]<m)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    cout<<"IMPOSSIBLE";
    nl;
    return 0;
}
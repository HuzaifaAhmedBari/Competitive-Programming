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
    int t = 1;
    cin>>t;
    while(t--)
    {
        ll n,k,x;
        cin>>n>>k>>x;
        vl arr(n);
        input(arr);
        reverse(all(arr));
        ll s = accumulate(all(arr),0LL);
        ll m = x/s;
        ll t = m*s;
        ll count = m*n;
        if(m>k)
        {
            cout<<0;
            nl;
            continue;
        }
        if(m>0 && m*s==x)
        {
            m--;
            count=m*n;
            t=m*s;
        }
        ll temp=0;
        ll sum=t;
        fori(0,n)
        {
            sum+=arr[i];
            if(sum>=x)
                break;
            temp++;
        }
        if((n*k)-count-temp<0)
            cout<<0;
        else
            cout<<(n*k)-count-temp;
        nl;
    }
    return 0;
}
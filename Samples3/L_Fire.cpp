//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//find_by_order(k): returns iterator to k-th smallest element (0-based)
//order_of_key(x): returns number of elements strictly less than x
#define ll long long int
#define ld long double
#define nl cout<<"\n"
#define re return 0
#define fs first
#define sc second
#define MOD 1000000007
#define pii pair<ll,ll>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vpii vector<pair<ll,ll>>
#define vvpii vector<vector<pair<ll,ll>>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define vc vector<char>
#define vcc vector<vector<char>>
#define vs vector<string>
#define vss vector<vector<string>>
#define all(vec) vec.begin(), vec.end()
#define allr(vec) vec.rbegin(), vec.rend()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(ll i=a;i<b;i++)
#define forj(a,b) for(ll j=a;j<b;j++)
#define fork(a,b) for(ll k=a;k<b;k++)
#define forr(a,b) for(ll r=a;r>=b;r--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)

template <typename A, typename B>
istream& operator>>(istream &in, pair<A,B> &p) {
    in >> p.first >> p.second;
    return in;
}
template <typename T>
istream& operator>>(istream &in, vector<T> &v) {
    for (auto &x : v) in >> x;
    return in;
}

template <typename A, typename B>
ostream& operator<<(ostream &out, const pair<A,B> &p) {
    out << p.first << " " << p.second;
    return out;
}
template <typename T>
ostream& operator<<(ostream &out, const vector<T> &v) {
    for (auto &x : v) out << x << " ";
    return out;
}

int main()
{
    io;
    ll n;
    cin>>n;
    vector<pair<pii,pii>> arr(n);
    fori(0,n)
        cin>>arr[i].fs>>arr[i].sc.fs;
    fori(0,n)
        arr[i].sc.sc = i;
    sort(all(arr),[](pair<pii,pii> x,pair<pii,pii> y){
        if(x.fs.sc!=y.fs.sc)
            return x.fs.sc<y.fs.sc;
        return x.sc.fs>y.sc.fs;
    });
    vl tim(n), last(n), val(n), loc(n);
    fori(0,n)
    {
        tim[i] = arr[i].fs.fs;
        last[i] = arr[i].fs.sc;
        val[i] = arr[i].sc.fs;
        loc[i] = arr[i].sc.sc;
    }
    ll m = *max_element(all(last));
    vll dp(n,vl(m,0));
    fori(0,n)
    {
        forj(0,m)
        {
            if(j>=last[i] and i)
                dp[i][j] = dp[i-1][j];
            if(j<last[i] and i and j-tim[i]>=0)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-tim[i]]+val[i]);
            else if(j<last[i] and i and j-tim[i]<0)
                dp[i][j] = dp[i-1][j];
            if(not i and j<last[i] and j-tim[i]>=0)
                dp[i][j] = val[i];
        }
    }
    vl ans;
    ll mx = *max_element(all(dp[n-1]));
    cout<<mx;
    nl;
    ll cur = -1;
    fori(0,m)
    {
        if(dp[n-1][i]==mx)
        {
            cur = i;
            break;
        }
    }
    forr(n-1,0)
    {
        if(r and dp[r-1][cur]==mx)
            continue;
        if(r)
        {
            ans.push_back(loc[r]+1);
            mx-=val[r];
            cur-=tim[r];
        }
        else if(mx!=0)
        {
            ans.push_back(loc[r]+1);
            mx-=val[r];
        }
    }
    // cout<<loc;
    // cout<<dp;
    reverse(all(ans));
    cout<<ans.size();
    nl;
    cout<<ans;
    nl;
    return 0;
}
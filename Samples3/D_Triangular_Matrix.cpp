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
    vs s(n);
    cin>>s;
    // queue<pii> q;
    // q.push({0LL,0LL});
    // string ans;
    // ans+=s[0][0];
    // function<bool(ll,ll)> safe = [&](ll x, ll y) {
    //     return x>=0 and y>=0 and x<n and y<=x;
    // };
    // while(not q.empty())
    // {
    //     ll x = q.size();
    //     fori(0,x)
    //     {

    //     }
    // }
    vvpii dp(n,vpii(n,pii{LLONG_MAX,LLONG_MAX}));
    dp[0][0] = {-1,-1};
    fori(1,n)
    {
        char mn = 'z'+1;
        forj(0,s[i].size())
        {
            if(j!=0)
                if(dp[i-1][j-1]!=pii{LLONG_MAX,LLONG_MAX})
                    mn = min(mn,s[i][j]);
            if(dp[i-1][j]!=pii{LLONG_MAX,LLONG_MAX})
                mn = min(mn,s[i][j]);
        }
        forj(0,s[i].size())
        {
            if(s[i][j]==mn)
            {
                if(dp[i-1][j]!=pii{LLONG_MAX,LLONG_MAX})
                    dp[i][j] = pii{i-1,j};
                else if(j-1>=0 and dp[i-1][j-1]!=pii{LLONG_MAX,LLONG_MAX})
                    dp[i][j] = pii{i-1,j-1};
            }
        }
    }
    pii start = pii{-1,-1};
    string ans;
    fori(0,n)
    {
        if(dp[n-1][i]!=pii{LLONG_MAX,LLONG_MAX})
        {
            ans+=s[n-1][i];
            start = dp[n-1][i];
            break;
        }
    }
    // fori(0,n)
    // {
    //     forj(0,s[i].size())
    //     {
    //         cout<<((dp[i][j]==pii{LLONG_MAX,LLONG_MAX})?pii{-1,-1}:dp[i][j])<<" : ";
    //     }
    //     nl;
    // }
    while(start!=pii{-1,-1})
    {
        ans+=s[start.fs][start.sc];
        start = dp[start.fs][start.sc];
    }
    reverse(all(ans));
    cout<<ans;
    nl;
    return 0;
}
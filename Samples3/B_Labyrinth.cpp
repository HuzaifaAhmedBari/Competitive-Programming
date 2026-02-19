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
istream& operator>>(istream &in, vector<pair<A,B>> &vp) {
    for (auto &p : vp) in >> p.first >> p.second;
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
template <typename A, typename B>
ostream& operator<<(ostream &out, const vector<pair<A,B>> &vp) {
    for (auto &p : vp) out << p.first << " " << p.second << "\n";
    return out;
}

int main()
{
    io;
    ll n,m;
    cin>>n>>m;
    ll s,f;
    cin>>s>>f;
    ll l,r;
    cin>>l>>r;
    s--;f--;
    vector<vector<char>> si(n,vector<char>(m));
    fori(0,n)
    {
        cin>>si[i];
    }
    ll ans = 0;
    queue<tuple<ll,ll,ll,ll>> q;
    q.push({s,f,0LL,0LL});
    vvpii visited(n,vpii(m,{LLONG_MAX,LLONG_MAX}));
    function<bool(ll,ll,ll,ll)> issafe = [&](ll x,ll y,ll a,ll b) {
        return x>=0 and x<n and y>=0 and y<m and a<=l and b<=r and (a<visited[x][y].fs or b<visited[x][y].sc) and si[x][y]!='*';
    };
    visited[s][f] = {0LL,0LL};
    while(not q.empty())
    {
        auto [j,o,p,i] = q.front();
        ll x = j, y = o, a = p, b = i;
        q.pop();
        if(issafe(x-1,y,a,b))
        {
            q.push({x-1,y,a,b});
            visited[x-1][y] = {a,b};
        }
        if(issafe(x+1,y,a,b))
        {
            q.push({x+1,y,a,b});
            visited[x+1][y] = {a,b};
        }
        if(issafe(x,y-1,a+1,b))
        {
            q.push({x,y-1,a+1,b});
            visited[x][y-1] = {a+1,b};
        }
        if(issafe(x,y+1,a,b+1))
        {
            q.push({x,y+1,a,b+1});
            visited[x][y+1] = {a,b+1};
        }
    }
    fori(0,n)
        ans += count_if(all(visited[i]),[](pii x){return x!=pii{LLONG_MAX,LLONG_MAX};});
    cout<<ans;
    nl;
    return 0;
}
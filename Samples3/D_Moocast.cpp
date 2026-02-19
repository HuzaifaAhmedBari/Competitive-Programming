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
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    ll n;
    cin>>n;
    vl weight(n);
    vpii pos(n);
    fori(0,n)
    {
        cin>>pos[i]>>weight[i];
    }
    vll adj(n);
    function<ld(ld,ld,ld,ld)>f = [&](ld px,ld py,ld ox,ld oy) {
        return (ld)(sqrt(pow(px-ox,2)+pow(py-oy,2)));
    };
    fori(0,n)
    {
        forj(0,n)
        {
            if(i==j)
                continue;
            if(f((ld)(pos[i].fs),(ld)(pos[i].sc),(ld)(pos[j].fs),(ld)(pos[j].sc))<=weight[i])
            {
                adj[i].push_back(j);
            }
        }
    }
    vb visited(n,false);
    ll ans = 0, mx=0;
    function<void(ll)> dfs = [&](ll u) {
        visited[u] = true;
        ans++;
        for(ll v:adj[u])
        {
            if(not visited[v])
            {
                dfs(v);
            }
        }
    };
    fori(0,n)
    {
        fill(all(visited),false);
        ans = 0;
        dfs(i);
        mx = max(mx,ans);
    }
    cout<<mx;
    nl;
    return 0;
}
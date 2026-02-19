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
    ll n,m,sp;
    cin>>n>>m>>sp;
    vcc s(n,vc(m));
    cin>>s;
    ll sx,sy,fx,fy,ans=-1;
    cin>>sx>>sy>>fx>>fy;
    sx--;sy--;
    fx--;fy--;
    queue<pii> q;
    q.push({sx,sy});
    vpii d = {{1,0},{-1,0},{0,1},{0,-1}};
    vll visited(n,vl(m,LLONG_MAX));
    visited[sx][sy] = 0;
    function<bool(ll,ll)> safe = [&](ll x,ll y) {
        return x>=0 and x<n and y>=0 and y<m and s[x][y]=='.';
    };
    while(not q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
        // cout<<x<<" "<<y;
        // nl;
        if(x==fx and y==fy)
            break;
        
        for(auto [cx,cy]:d)
        {
            fori(1,sp+1)
            {
                ll dx = x+(cx*i), dy = y+(cy*i);
                if(safe(dx,dy))
                {
                    if(visited[dx][dy]<visited[x][y]+1)
                        break;
                    if(visited[x][y]+1<visited[dx][dy])
                    {
                        q.push({dx,dy});
                        visited[dx][dy] = visited[x][y]+1;
                    }
                }
                else
                    break;
            }
        }
    }
    cout<<((visited[fx][fy]==LLONG_MAX)? -1 : visited[fx][fy]);
    nl;
    return 0;
}
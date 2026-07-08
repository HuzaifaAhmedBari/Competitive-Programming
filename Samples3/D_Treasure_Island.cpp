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
    ll t = 1;
    // cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vcc s(n,vc(m));
        vll adj(n,vl(m,0));
        map<ll,pair<bool,bool>> ma;
        cin>>s;
        ll ans = 2;
        function<bool(ll,ll)> safe = [&](ll x, ll y) {
            return x>=0 and x<=n-1 and y>=0 and y<=m-1 and s[x][y] == '#';
        };
        function<bool(ll,ll)> safe2 = [&](ll x, ll y) {
            return x>=0 and x<=n-1 and y>=0 and y<=m-1 and s[x][y] == '.';
        };
        bool l, r;
        function<bool(ll,ll)> zero = [&](ll x,ll y) {
            s[x][y] = 'y';
            if(x==n-1 and y==m-1)
                return true;
            if(safe2(x+1,y))
                if(zero(x+1,y))
                    return true;
            if(safe2(x,y+1))
                if(zero(x,y+1))
                    return true;
            return false;
        };
        if(!(zero(0,0)))
        {
            cout<<0;
            nl;
            re;
        }
        function<void(ll,ll,ll)> dfs = [&](ll x, ll y, ll cur) {
            s[x][y] = 'x';
            adj[x][y] = cur;
            if(x==0 or y==m-1)
                r = true;
            if(y==0 or x==n-1)
                l = true;
            for(auto dxx:{-1,1,0})
            {
                for(auto dyy:{-1,1,0})
                {
                    ll dx = x+dxx;
                    ll dy = y+dyy;
                    if(dxx==0 and dyy==0)
                        continue;
                    if(safe(dx,dy))
                    {
                        dfs(dx,dy,cur);
                    }
                }
            }
        };
        ll z = 1;
        fori(0,n)
        {
            forj(0,m)
            {
                if(s[i][j]=='#')
                {
                    l = r = false;
                    dfs(i,j,z);
                    ma[z].first = l;
                    ma[z].second = r;
                    z++;
                }
            }
        }
        function<bool(ll,ll)> left = [&](ll x,ll y) {
            for(auto dxx:{-1,1,0})
            {
                for(auto dyy:{-1,1,0})
                {
                    ll dx = x+dxx;
                    ll dy = y+dyy;
                    if(dxx==0 and dyy==0)
                        continue;
                    if(dx==0 and dy==0)
                        continue;
                    if(dx==n-1 and dy==m-1)
                        continue;
                    if(dy==0 or dx==n-1)
                        return true;
                }
            }
            return false;
        };
        function<bool(ll,ll)> right = [&](ll x,ll y) {
            for(auto dxx:{-1,1,0})
            {
                for(auto dyy:{-1,1,0})
                {
                    ll dx = x+dxx;
                    ll dy = y+dyy;
                    if(dxx==0 and dyy==0)
                        continue;
                    if(dx==0 and dy==0)
                        continue;
                    if(dx==n-1 and dy==m-1)
                        continue;
                    if(dx==0 or dy==m-1)
                        return true;
                }
            }
            return false;
        };
        fori(0,n)
        {
            forj(0,m)
            {
                if(s[i][j]=='x')
                {
                    z = adj[i][j];
                    if(ma[z].first and ma[z].second)
                        ans = 0;
                    if(left(i,j) and ma[z].second)
                        ans = min(ans,1LL);
                    if(right(i,j) and ma[z].first)
                        ans = min(ans,1LL);
                    for(auto dxx:{-1,1,0})
                    {
                        for(auto dyy:{-1,1,0})
                        {
                            if(dxx==0 and dyy==0)
                                continue;
                            for(auto dzx:{-1,1,0})
                            {
                                for(auto dzy:{-1,1,0})
                                {
                                    if(dzx==0 and dzy==0)
                                        continue;
                                    ll x = i+dxx+dzx;
                                    ll y = j+dyy+dzy;
                                    if(x>=0 and x<=n-1 and y>=0 and y<=m-1)
                                    {
                                        if(adj[i][j]!=adj[x][y])
                                        {
                                            ll k = adj[x][y];
                                            if((ma[z].first or ma[k].first) and (ma[z].second or ma[k].second))
                                            {
                                                ans = min(ans,1LL);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if((n==1 or m==1) and ans!=0)
            ans = 1;

        cout<<ans;
        nl;
    }
    return 0;
}
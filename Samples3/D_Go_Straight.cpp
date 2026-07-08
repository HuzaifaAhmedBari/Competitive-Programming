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

ll n,m;
vcc s;
vector<vector<array<bool,4>>> visited;
map<char,pii> d;
string ans;

bool safe(pii cur) {
    return cur.fs>=0 and cur.fs<n and cur.sc>=0 and cur.sc<m and s[cur.fs][cur.sc]!='#';
}

bool dfs(pii cur, char dir) {
    if(s[cur.fs][cur.sc]=='G')
        {
            return true;
        }
        if(s[cur.fs][cur.sc]=='o')
        {
            pii nx = cur;
            nx.fs+=d[dir].fs;
            nx.sc+=d[dir].sc;
            if(safe(nx))
            {
                if(dir=='L' and not visited[cur.fs][cur.sc][0])
                {
                    visited[cur.fs][cur.sc][0] = true;
                    if(dfs(nx,dir))
                    {
                        ans+=dir;
                        return true;
                    }
                }
                else if(dir=='R' and not visited[cur.fs][cur.sc][1])
                {
                    visited[cur.fs][cur.sc][1] = true;
                    if(dfs(nx,dir))
                    {
                        ans+=dir;
                        return true;
                    }
                }
                else if(dir=='U' and not visited[cur.fs][cur.sc][2])
                {
                    visited[cur.fs][cur.sc][2] = true;
                    if(dfs(nx,dir))
                    {
                        ans+=dir;
                        return true;
                    }
                }
                else if(dir=='D' and not visited[cur.fs][cur.sc][3])
                {
                    visited[cur.fs][cur.sc][3] = true;
                    if(dfs(nx,dir))
                    {
                        ans+=dir;
                        return true;
                    }
                }
            }
        }
        else if(s[cur.fs][cur.sc]=='x')
        {
            for(auto [c,ds]:d)
            {
                if(c==dir)
                    continue;
                pii nx = cur;
                nx.fs+=ds.fs;
                nx.sc+=ds.sc;
                if(safe(nx))
                {
                    if(c=='L' and not visited[cur.fs][cur.sc][0])
                    {
                        visited[cur.fs][cur.sc][0] = true;
                        if(dfs(nx,c))
                        {
                            ans+=c;
                            return true;
                        }
                    }
                    else if(c=='R' and not visited[cur.fs][cur.sc][1])
                    {
                        visited[cur.fs][cur.sc][1] = true;
                        if(dfs(nx,c))
                        {
                            ans+=c;
                            return true;
                        }
                    }
                    else if(c=='U' and not visited[cur.fs][cur.sc][2])
                    {
                        visited[cur.fs][cur.sc][2] = true;
                        if(dfs(nx,c))
                        {
                            ans+=c;
                            return true;
                        }
                    }
                    else if(c=='D' and not visited[cur.fs][cur.sc][3])
                    {
                        visited[cur.fs][cur.sc][3] = true;
                        if(dfs(nx,c))
                        {
                            ans+=c;
                            return true;
                        }
                    }
                }
            }
        }
        else
        {
            for(auto [c,ds]:d)
            {
                pii nx = cur;
                nx.fs+=ds.fs;
                nx.sc+=ds.sc;
                if(safe(nx))
                {
                    if(c=='L' and not visited[cur.fs][cur.sc][0])
                    {
                        visited[cur.fs][cur.sc][0] = true;
                        if(dfs(nx,c))
                        {
                            ans+=c;
                            return true;
                        }
                    }
                    else if(c=='R' and not visited[cur.fs][cur.sc][1])
                    {
                        visited[cur.fs][cur.sc][1] = true;
                        if(dfs(nx,c))
                        {
                            ans+=c;
                            return true;
                        }
                    }
                    else if(c=='U' and not visited[cur.fs][cur.sc][2])
                    {
                        visited[cur.fs][cur.sc][2] = true;
                        if(dfs(nx,c))
                        {
                            ans+=c;
                            return true;
                        }
                    }
                    else if(c=='D' and not visited[cur.fs][cur.sc][3])
                    {
                        visited[cur.fs][cur.sc][3] = true;
                        if(dfs(nx,c))
                        {
                            ans+=c;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
}

int main()
{
    io;
    cin>>n>>m;
    s.assign(n,vc(m));
    cin>>s;
    pii start;
    fori(0,n)
        forj(0,m)
            if(s[i][j]=='S')
                start = pii{i,j};

    visited.assign(n,vector<array<bool,4>>(m));
    d['L'] = pii{0,-1};
    d['R'] = pii{0,1};
    d['U'] = pii{-1,0};
    d['D'] = pii{1,0};

    if(dfs(start,'L'))
        Yes(1),nl,reverse(all(ans)),cout<<ans;
    else
        Yes(0);
    nl;

    return 0;
}
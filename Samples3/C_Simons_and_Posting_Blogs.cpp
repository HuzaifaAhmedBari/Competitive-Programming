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
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vll adj(n);
        fori(0,n)
        {
            set<ll> s;
            ll x;
            cin>>x;
            vl temp(x);
            cin>>temp;
            forr(x-1,0)
            {
                if(s.count(temp[r]))
                    continue;
                adj[i].push_back(temp[r]);
                s.insert(temp[r]);
            }
            reverse(all(adj[i]));
        }
        map<ll,ll> m;
        set<ll> used;
        while(used.size()!=n)
        {
            set<ll> cand;
            fori(0,n)
                if(not used.count(i))
                    cand.insert(i);
            ll cur = 0;
            while(cand.size()>1)
            {
                ll mn = LLONG_MAX;
                bool flag=false;
                for(auto x:cand)
                {
                    ll idx = 0;
                    forr(adj[x].size()-1,0)
                    {
                        if(m.count(adj[x][r]))
                            continue;
                        if(idx==cur)
                        {
                            mn = min(mn,adj[x][r]);
                            idx = -1;
                            break;
                        }
                        idx++;
                    }
                    if(idx!=-1)
                    {
                        used.insert(x);
                        forr(adj[x].size()-1,0)
                        {
                            if(m.count(adj[x][r]))
                                continue;
                            m[adj[x][r]] = 1;
                            cout<<adj[x][r]<<" ";
                        }
                        flag=true;
                        break;
                    }
                }
                if(flag)
                    break;
                vl extra;
                for(auto x:cand)
                {
                    ll idx = 0;
                    forr(adj[x].size()-1,0)
                    {
                        if(m.count(adj[x][r]))
                            continue;
                        if(idx==cur)
                        {
                            if(adj[x][r]!=mn)
                            {
                                extra.push_back(x);
                            }
                            break;
                        }
                        idx++;
                    }
                }
                for(auto x:extra)
                    cand.erase(x);
                cur++;
            }
            if(cand.size()==1)
            {
                ll z = 0;
                for(auto x:cand)
                    z = x;
                used.insert(z);
                forr(adj[z].size()-1,0)
                {
                    if(m.count(adj[z][r]))
                        continue;
                    m[adj[z][r]] = 1;
                    cout<<adj[z][r]<<" ";
                }
            }
        }
        nl;
    }
    return 0;
}
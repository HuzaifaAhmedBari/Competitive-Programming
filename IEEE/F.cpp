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
#define us unordered_set<ll>
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

vb is_prime;
void sieve(ll n) {
    is_prime.assign(n+1,true);
    is_prime[0] = is_prime[1] = false;
    for(ll i=2;i*i<=n;i++) {
        if(is_prime[i]) {
            for(ll j=i*i;j<=n;j+=i)
                is_prime[j] = false;
        }
    }
}
bool isprime(ll n) {
    if(n<2)	return false;
    if(n==2 || n==3)	return true;
    if(n%2==0 || n%3==0)	return false;
    for(ll i=5;i*i<=n;i++)
    {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}
ll nextprime(ll n)	{ return (isprime(n))? n : nextprime(n+1); }
ll sum_digits(ll n)	{ return (n<10)? n : n%10 + sum_digits(n/10); }
ll gcd(ll a, ll b)	{ return (b==0)? a : gcd(b,a%b); }
ll lcm(ll a, ll b)	{ return (a*b)/gcd(a,b); }
using uint = unsigned int;
const int INF = INT_MAX;
int main(){
    io;
    int N,Q;
    cin>>N>>Q;
    vector<int> color(N+1);
    for(int i=1;i<=N;++i) scanf("%d",&color[i]);
    int mEdges = 2*(N-1)+5;
    vector<int> head(N+1, -1);
    vector<int> to(mEdges);
    vector<int> nxt(mEdges);
    int ec=0;
    auto addEdge = [&](int u,int v){
        to[ec]=v; nxt[ec]=head[u]; head[u]=ec++;
    };
    for(int i=0;i<N-1;++i){
        int u,v; scanf("%d %d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    vector<int> dist(N+1, INF);
    vector<int> bfsq; bfsq.reserve(N);
    for(int i=1;i<=N;++i) if(color[i]==1){ dist[i]=0; bfsq.push_back(i); }
    size_t qi=0;
    while(qi<bfsq.size()){
        int u=bfsq[qi++];
        for(int e=head[u]; e!=-1; e=nxt[e]){
            int v=to[e];
            if(dist[v]==INF){ dist[v]=dist[u]+1; bfsq.push_back(v); }
        }
    }
    vector<int> parent(N+1), depth(N+1), order; order.reserve(N);
    parent[1]=0; depth[1]=0;
    vector<int> stackv; stackv.reserve(N);
    stackv.push_back(1);
    while(!stackv.empty()){
        int u=stackv.back(); stackv.pop_back();
        order.push_back(u);
        for(int e=head[u]; e!=-1; e=nxt[e]){
            int v=to[e];
            if(v==parent[u]) continue;
            parent[v]=u;
            depth[v]=depth[u]+1;
            stackv.push_back(v);
        }
    }
    vector<int> sz(N+1,1), heavy(N+1,-1);
    for(int i=(int)order.size()-1;i>0;--i){
        int u=order[i];
        int p=parent[u];
        if(p){
            sz[p]+=sz[u];
            if(heavy[p]==-1 || sz[u]>sz[heavy[p]]) heavy[p]=u;
        }
    }
    vector<int> headChain(N+1), pos(N+1);
    int cur=0;
    vector<int> st2; st2.reserve(N);
    st2.push_back(1);
    headChain[1]=1;
    while(!st2.empty()){
        int u=st2.back(); st2.pop_back();
        int h=u;
        for(int v=u; v!=-1; v=heavy[v]){
            headChain[v]=h;
            pos[v]=cur++;
            for(int e=head[v]; e!=-1; e=nxt[e]){
                int w=to[e];
                if(w==parent[v] || w==heavy[v]) continue;
                st2.push_back(w);
                headChain[w]=w;
            }
        }
    }
    int sizeST=1;
    while(sizeST < N) sizeST <<= 1;
    vector<int> seg(2*sizeST, INF);
    for(int u=1; u<=N; ++u) seg[sizeST + pos[u]] = dist[u];
    for(int i=sizeST-1;i>0;--i) seg[i]=min(seg[i<<1], seg[i<<1|1]);
    auto segQuery = [&](int l,int r){
        l += sizeST; r += sizeST;
        int res = INF;
        while(l<=r){
            if(l&1) res = min(res, seg[l++]);
            if(!(r&1)) res = min(res, seg[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    };
    auto pathQuery = [&](int u,int v){
        int res = INF;
        while(headChain[u] != headChain[v]){
            if(depth[headChain[u]] < depth[headChain[v]]) swap(u,v);
            int h = headChain[u];
            res = min(res, segQuery(pos[h], pos[u]));
            u = parent[h];
        }
        if(depth[u] > depth[v]) swap(u,v);
        res = min(res, segQuery(pos[u], pos[v]));
        return res;
    };
    for(int i=0;i<Q;++i){
        int u,v; scanf("%d %d",&u,&v);
        int ans = pathQuery(u,v);
        printf("%d\n", ans);
    }
    return 0;
}
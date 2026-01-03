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
    for(ll i=5;i*i<=n;i+=6)
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
ll key(int u,int v)
{
    return ( (ll)u<<32 ) | (ll)v;
}
ll countTriples(const vl& a,const vl& b,const vl& c,int W){
    if(a.empty()||b.empty()||c.empty())
        return 0;
    vl prefB(b.size()), choty(b.size());
    int p=0;
    for(int i=0;i<b.size();++i){
        while(p<(int)a.size() and a[p]<b[i])
            ++p;
        choty[i]=p;
    }
    vl pref(choty.size());
    long long run=0;
    for(int i=0;i<choty.size();++i)
    {
        run+=choty[i];
        pref[i]=run;
    }

    long long ans=0;
    int q=0; 
    int r=0; 
    for(int z: c){
        while(r<(int)b.size() && b[r]<z)
            ++r;
        int k=r-1;
        if(k<0)
            continue;
        int limit=z-W;
        while(q<(int)a.size() && a[q]<limit)
            ++q;
        int T=q;
        auto it=upper_bound(choty.begin(), choty.begin()+k+1, T);
        int pos=(int)(it-choty.begin());
        if(pos>k) continue;
        ll sum = pref[k] - (pos?pref[pos-1]:0);
        ll cntY = k - pos + 1;
        ans += sum - 1LL*T*cntY;
    }
    return ans;
}
int main()
{
    io;
    int N,M,A;
    cin>>N>>M>>A;
    unordered_map<ll, vl> times;
    vll outN(N), inN(N);
    vector<us> bahar(N), andar(N);

    for(int i=0;i<M;++i){
        int u,v,t;
        cin>>u>>v>>t;
        times[key(u,v)].push_back(t);
        if(!bahar[u].count(v))
        {
            bahar[u].insert(v);
            outN[u].push_back(v);
        }
        if(!andar[v].count(u))
        {
            andar[v].insert(u);
            inN[v].push_back(u);
        }
    }
    for(auto &kv: times)
        sort(kv.second.begin(), kv.second.end());

    ll c1=0,c2=0,c3=0;

    for(int A0=0;A0<N;++A0)
    {
        for(int B: outN[A0])
        {
            auto &AB = times[key(A0,B)];
            for(int C: outN[B])
            {
                if(C==A0)
                    continue;
                if(!bahar[C].count(A0))
                    continue;
                c1 += countTriples(AB, times[key(B,C)], times[key(C,A0)], A);
            }
        }
    }
    for(int A0=0;A0<N;++A0)
    {
        auto &outs = outN[A0];
        for(int i=0;i<(int)outs.size();++i)
        {
            int B=outs[i];
            auto &AB = times[key(A0,B)];
            for(int j=0;j<(int)outs.size();++j)
            {
                if(i==j)
                    continue;
                int C=outs[j];
                if(!bahar[B].count(C))
                    continue;
                c2 += countTriples(AB, times[key(A0,C)], times[key(B,C)], A);
            }
        }
    }
    for(int A0=0;A0<N;++A0)
    {
        for(int B: outN[A0])
        {
            if(!bahar[B].count(A0))
                continue;
            auto &AB = times[key(A0,B)];
            auto &BA = times[key(B,A0)];
            for(int C: inN[B])
            {
                if(C==A0)
                    continue;
                c3 += countTriples(AB, times[key(C,B)], BA, A);
            }
        }
    }

    cout<<c1<<" "<<c2<<" "<<c3;
    nl;
    return 0;
}
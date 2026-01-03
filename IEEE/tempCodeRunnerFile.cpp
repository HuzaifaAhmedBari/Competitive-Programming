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
using i128 = __int128_t;
#define ld long double
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
struct Line {
    ll m;
    ll b;
    Line() {}
    Line(ll _m, ll _b) : m(_m), b(_b) {}
    inline i128 value(ll x) const { return (i128)m * (i128)x + (i128)b; }
};

struct MonoCHT {
    deque<Line> dq;
    static inline bool is_bad(const Line &l1, const Line &l2, const Line &l3) {
        i128 left = (i128)(l2.b - l1.b) * (i128)(l2.m - l3.m);
        i128 right = (i128)(l3.b - l2.b) * (i128)(l1.m - l2.m);
        return left >= right;
    }
    void clear() { dq.clear(); }
    bool empty() const { return dq.empty(); }
    void add_line(ll m, ll b) {
        Line nl(m,b);
        if (!dq.empty() && dq.back().m == m) {
            if (dq.back().b >= b) return;
            else dq.pop_back();
        }
        while (dq.size() >= 2 && is_bad(dq[dq.size()-2], dq[dq.size()-1], nl)) dq.pop_back();
        dq.push_back(nl);
    }
    ll query(ll x) {
        while (dq.size() >= 2 && dq[0].value(x) <= dq[1].value(x)) dq.pop_front();
        if (dq.empty()) return LLONG_MIN / 4;
        i128 val = dq.front().value(x);
        if (val > (i128)LLONG_MAX) return LLONG_MAX;
        if (val < (i128)LLONG_MIN) return LLONG_MIN;
        return (ll)val;
    }
};

int main() {
    io;
    int n, m;
    cin>>n;
    string a, b;
    cin >> a;
    cin >> m;
    cin >> b;
    ll match, mismatch, gap;
    cin >> match >> mismatch >> gap;
    a = " " + a;
    b = " " + b;
    int W = m + 1;
    vector<ll> dp((n+1) * (m+1), LLONG_MIN/4);
    auto DP = [&](int i, int j) -> ll& { return dp[i * W + j]; };
    DP(0,0) = 0;
    for (int j = 1; j <= m; ++j) DP(0,j) = (ll)((i128)gap * j * j);
    for (int i = 1; i <= n; ++i) DP(i,0) = (ll)((i128)gap * i * i);
    vector<MonoCHT> colHull(m+1);
    for (int j = 0; j <= m; ++j) {
        ll intercept0 = DP(0,j);
        colHull[j].add_line(0, intercept0);
    }
    for (int i = 1; i <= n; ++i) {
        MonoCHT rowHull;
        rowHull.add_line(0, DP(i,0));
        for (int j = 1; j <= m; ++j) {
            ll v1 = DP(i-1, j-1) + ((a[i]==b[j]) ? match : mismatch);
            ll best_col = colHull[j].query(i);
            ll v2 = (ll)((i128)gap * i * i + (i128)best_col);
            ll best_row = rowHull.query(j);
            ll v3 = (ll)((i128)gap * j * j + (i128)best_row);
            ll best = v1;
            if (v2 > best) best = v2;
            if (v3 > best) best = v3;
            DP(i,j) = best;
            ll mt = (ll)(-2) * gap * (ll)j;
            ll bt = DP(i,j) + (ll)((i128)gap * j * j);
            rowHull.add_line(mt, bt);
            ll mc = (ll)(-2) * gap * (ll)i;
            ll bc = DP(i,j) + (ll)((i128)gap * i * i);
            colHull[j].add_line(mc, bc);
        }
    }
    cout << DP(n,m) << '\n';
    return 0;
}
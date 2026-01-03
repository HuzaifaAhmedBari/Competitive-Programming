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
int main()
{
    io;
    solve();
    return 0;
}
template <class T>
struct SegTree
{
    int n;
    vector<T> seg, pre, post;
    T ID; // identity element (e.g. 0 for sum, -INF for max)

    SegTree(int n, T id) : n(n), ID(id)
    {
        seg.assign(4 * n, ID);
    }

    SegTree(const vector<T> &a) : n((int)a.size())
    {
        seg.assign(4 * n, 0);
        pre.assign(4 * n, 0);
        post.assign(4 * n, 0);
        build(0, 0, n - 1, a);
    }

    void build(int i, int l, int r, const vector<T> &a)
    {
        if (l == r)
        {
            seg[i] = a[l];
            pre[i] = a[l];
            post[i] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * i + 1, l, m, a);
        build(2 * i + 2, m + 1, r, a);
        seg[i] = (seg[2 * i + 1] + seg[2 * i + 2]);
        pre[i] = max({pre[2 * i + 1], seg[2 * i + 1] + pre[2 * i + 2], seg[2 * i + 1], seg[i]});
        post[i] = max({post[2 * i + 2], seg[2 * i + 2] + post[2 * i + 1], seg[2 * i + 2], seg[i]});
    }
    vector<T> query(int i, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
            return {-INT_MAX, 0, -INT_MAX};
        if (ql <= l && r <= qr)
            return {pre[i], seg[i], post[i]};
        int m = (l + r) / 2;
        vector<T> left = query(2 * i + 1, l, m, ql, qr), right = query(2 * i + 2, m + 1, r, ql, qr);
        vector<T> cur(3);
        cur[1] = left[1] + right[1];
        cur[0] = max(left[0], left[1] + right[0]); 
        cur[2] = max(right[2], right[1] + left[2]); 
        return cur;
        // return op(query(2 * i + 1, l, m, ql, qr),
        //           query(2 * i + 2, m + 1, r, ql, qr));
    }

    vector<T> query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

// Example usage:
// auto op = [](long long a, long long b){ return a + b; };
// SegTree<long long, decltype(op)> st(arr, 0LL, op);
// st.update(2, 5);
// cout << st.query(1, 3) << "\n";
void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    inputv(arr);
    SegTree<int> apna(arr);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        vi ans = apna.query(l - 1, r-1); 
        cout<<*max_element(all(ans))<<endl;
    }
}
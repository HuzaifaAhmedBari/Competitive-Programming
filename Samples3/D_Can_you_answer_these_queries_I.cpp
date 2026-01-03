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
struct Node {
    ll pre = INT_MIN, suf = INT_MIN, sum = 0, mx = LLONG_MIN;

    Node() : pre(INT_MIN), suf(INT_MIN), sum(0), mx(LLONG_MIN) {}
    Node(ll x) : pre(x), suf(x), sum(x), mx(x) {}
    Node(ll a, ll b,ll c,ll d) : pre(a), suf(b), sum(c), mx(d) {}

    // Change The Merge Function According to Segments Overlap Required
    static Node merge(const Node &a, const Node &b) {
        return Node(max(a.pre,a.sum+b.pre),max(b.suf,b.sum+a.suf),a.sum+b.sum,max({a.mx,b.mx,a.suf+b.pre}));
    }
};

class SegmentTree {
    ll n;
    vector<Node> tree;
    vl arr, lazy;
    vb has_lazy;

public:
    SegmentTree(const vl &input) {
        arr = input;
        n = arr.size();
        tree.assign(4 * n, Node());
        lazy.assign(4 * n, 0);
        has_lazy.assign(4 * n, false);
        build(1, 0, n - 1);
    }

private:
    void build(ll idx, ll l, ll r) {
        if (l == r) {
            tree[idx] = Node(arr[l]);
            return;
        }
        ll mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        tree[idx] = Node::merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    Node query(ll ql, ll qr, ll idx, ll l, ll r) {
        if(qr < l || r < ql)
            return Node();
        if(ql <= l && r <= qr)
            return tree[idx];
        ll mid = (l + r) / 2;
        return Node::merge(
            query(ql, qr, 2 * idx, l, mid),
            query(ql, qr, 2 * idx + 1, mid + 1, r)
        );
    }

public:
    // Public interfaces
    ll query(ll l, ll r) { return query(l, r, 1, 0, n - 1).mx; }
};

int main()
{
    io;
    ll n;
    cin>>n;
    vl arr(n);
    cin>>arr;
    ll q;
    cin>>q;
    SegmentTree st(arr);
    while(q--)
    {
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        cout<<st.query(u,v);
        nl;
    }
    return 0;
}
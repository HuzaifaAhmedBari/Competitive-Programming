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

struct Node {
    ll mn1,mn2,mx1,mx2;

    Node() : mn1(LLONG_MAX), mn2(LLONG_MAX), mx1(LLONG_MIN), mx2(LLONG_MIN) {}
    Node(ll a,ll b,ll c,ll d) : mn1(a), mn2(b), mx1(c), mx2(d) {}

    // Change The Merge Function According to Segments Overlap Required
    static Node merge(const Node &a, const Node &b) {
        return Node(min(a.mn1,b.mn1),min(a.mn2,b.mn2),max(a.mx1,b.mx1),max(a.mx2,b.mx2));
    }
};

class SegmentTree {
    ll n;
    vector<Node> tree;
    vpii arr;
    vl lazy;
    vb has_lazy;

public:
    SegmentTree(const vpii &input) {
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
            ll sum = arr[l].fs+arr[l].sc;
            ll dif = arr[l].fs-arr[l].sc;
            tree[idx] = Node(sum,dif,sum,dif);
            return;
        }
        ll mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        tree[idx] = Node::merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    // void apply(ll idx, ll l, ll r, ll val) {
    //     // ----- Set operation -----
    //     tree[idx] = Node((r - l + 1) * val);
    //     lazy[idx] = val;
    //     has_lazy[idx] = true;

    //     // ----- Add operation -----
    //     // tree[idx].val += (r - l + 1) * val;
    //     // lazy[idx] += val;
    //     // has_lazy[idx] = true;
    // }

    // void push(ll idx, ll l, ll r) {
    //     if (!has_lazy[idx] || l == r) return;
    //     ll mid = (l + r) / 2;
    //     apply(2 * idx, l, mid, lazy[idx]);
    //     apply(2 * idx + 1, mid + 1, r, lazy[idx]);
    //     lazy[idx] = 0;
    //     has_lazy[idx] = false;
    // }

    void update_range(ll ql, ll qr, pii val, ll idx, ll l, ll r) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            return;
        }
        ll mid = (l + r) / 2;
        update_range(ql, qr, val, 2 * idx, l, mid);
        update_range(ql, qr, val, 2 * idx + 1, mid + 1, r);
        tree[idx] = Node::merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    void update_point(ll pos, pii val, ll idx, ll l, ll r) {
        if (l == r) {
            ll sum = val.fs+val.sc;
            ll dif = val.fs-val.sc;
            tree[idx] = Node(sum,dif,sum,dif);
            return;
        }
        ll mid = (l + r) / 2;
        if (pos <= mid)
            update_point(pos, val, 2 * idx, l, mid);
        else
            update_point(pos, val, 2 * idx + 1, mid + 1, r);
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
    void update(ll l, ll r, pii val) { update_range(l, r, val, 1, 0, n - 1); }     // range update
    void update(ll pos, pii val) { update_point(pos, val, 1, 0, n - 1); }          // point update
    Node query(ll l, ll r) { return query(l, r, 1, 0, n - 1); }
};

int main()
{
    io;
    ll n,q;
    cin>>n>>q;
    vpii arr(n);
    cin>>arr;
    SegmentTree st(arr);
    while(q--)
    {
        ll m;
        cin>>m;
        if(m==1)
        {
            ll i,x,y;
            cin>>i>>x>>y;
            i--;
            st.update(i,{x,y});
        }
        else
        {
            ll l,r,x,y;
            cin>>l>>r>>x>>y;
            l--;r--;
            Node a = st.query(l,r);
            ll sum = x+y;
            ll dif = x-y;
            ll ans = max({abs(sum-a.mn1),abs(sum-a.mx1),abs(dif-a.mn2),abs(dif-a.mx2)});
            cout<<ans;
            nl;
        }
    }
    return 0;
}
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

ll hilbertOrder(ll x, ll y, ll pow = 21, ll rot = 0) {
    if (pow == 0) return 0;

    ll hpow = 1 << (pow - 1);
    ll seg = (x < hpow) ? ((y < hpow) ? 0 : 3)
                     : ((y < hpow) ? 1 : 2);

    seg = (seg + rot) & 3;
    const ll rotateDelta[4] = {3, 0, 0, 1};
    ll nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    ll nrot = (rot + rotateDelta[seg]) & 3;

    ll subSquareSize = 1LL << (2 * pow - 2);
    ll ord = seg * subSquareSize;

    ll add = hilbertOrder(nx, ny, pow - 1, nrot);
    ord += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);

    return ord;
}

struct Query {
    ll l, r, id;
    ll ord;

    void calcOrder() {
        ord = hilbertOrder(l, r);
    }
};

bool cmp(const Query &a, const Query &b) {
    return a.ord < b.ord;
}

const ll MAXN = 200005;
ll A[MAXN];
ll ans[MAXN];

ll freq[1000005];
ll current_answer = 0;

// ------------ ADD / REMOVE FUNCTIONS ------------

void add(ll idx) {
    ll x = A[idx];
    // Example: number of distinct elements
    if (freq[x] == 0) current_answer++;
    freq[x]++;
}

void remove_(ll idx) {
    ll x = A[idx];
    freq[x]--;
    if (freq[x] == 0) current_answer--;
}

// ------------ Example MAIN ------------
// ll main() {
// 	ll n, q;
// 	cin >> n >> q;
// 	for (ll i = 0; i < n; i++)
// 		cin >> A[i];
// 	vector<Query> queries(q);
// 	for (ll i = 0; i < q; i++) {
// 		cin >> queries[i].l >> queries[i].r;
// 		queries[i].l--;  // convert to 0-based
// 		queries[i].r--;
// 		queries[i].id = i;
// 		queries[i].calcOrder();
// 	}
// 	sort(queries.begin(), queries.end(), cmp);
// 	ll curL = 0, curR = -1;
// 	for (auto &qu : queries) {
// 		while (curL > qu.l) add(--curL);
// 		while (curR < qu.r) add(++curR);
// 		while (curL < qu.l) remove_(curL++);
// 		while (curR > qu.r) remove_(curR--);
//
// 		ans[qu.id] = current_answer;
// 	}
// 	for (ll i = 0; i < q; i++)
// 		cout << ans[i] << "\n";
// 	return 0;
// }


//Using my hilbert Order Curve Optimization for Mo's Alogrithm to sort the ranges
int main()
{
    io;
    ll n;
    cin>>n;
    vector<Query> arr(n);
    fori(0,n)
    {
        cin>>arr[i].l>>arr[i].r;
        arr[i].id = i+1;
        arr[i].calcOrder();
    }
    sort(arr.begin()+1,arr.end(),[&](Query a, Query b){
        return abs(a.ord-arr[0].ord)<abs(b.ord-arr[0].ord);
    });
    fori(0,n)
    {
        cout<<arr[i].id<<" ";
    }
    nl;
    return 0;
}
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
struct Node {
    ll v;
    Node* l = nullptr;
    Node* r = nullptr;
    Node(ll x) : v(x) {}
};
struct Info {
    bool isB;
    ll sum;
    ll mn;
    ll mx;
};
ll ans;
Info dfs(Node* node){
    if(!node) return {true, 0, LLONG_MAX, LLONG_MIN};
    Info L = dfs(node->l);
    Info R = dfs(node->r);
    if(L.isB && R.isB && L.mx < node->v && node->v < R.mn){
        ll s = L.sum + R.sum + node->v;
        ans = max(ans, s);
        ll mn = min(L.mn, (ll)node->v);
        ll mx = max(R.mx, (ll)node->v);
        return {true, s, mn, mx};
    }
    return {false, 0, 0, 0};
}
int main()
{
    io;
    ll t = 1;
    //cin>>t;
    while(t--)
    {
        string line;
        do {
            if(!std::getline(cin, line)) break;
        } while(line.find_first_not_of(" \t\r\n") == string::npos);

        vector<ll> a;
        if(!line.empty()){
            stringstream ss(line);
            ll x;
            while(ss >> x) a.push_back(x);
        }
        if(a.empty()){
            cout << 0; nl;
            continue;
        }
        if(a[0] == -1){
            cout << 0; nl;
            continue;
        }
        Node* root = new Node(a[0]);
        queue<Node*> q;
        q.push(root);
        int idx = 1;
        while(idx < (int)a.size() && !q.empty()){
            Node* cur = q.front(); q.pop();
            if(idx < (int)a.size()){
                if(a[idx] != -1){
                    cur->l = new Node(a[idx]);
                    q.push(cur->l);
                }
                idx++;
            }
            if(idx < (int)a.size()){
                if(a[idx] != -1){
                    cur->r = new Node(a[idx]);
                    q.push(cur->r);
                }
                idx++;
            }
        }
        ans = 0;
        dfs(root);
        cout << ans; nl;
    }
    return 0;
}
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
    for(ll i=2;i*i<=n;i++)
    {
        if(is_prime[i])
        {
            for(ll j=i*i;j<=n;j+=i)
                is_prime[j] = false;
        }
    }
}
int main()
{
    io;
    ll t = 1;
    cin>>t;
    sieve(1e6);
    vl spf;
    fori(0,1e6) if(is_prime[i]) spf.push_back(i);
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        bool flag = true;
        forr(n,max(n-10000,k+1)) {
            ll y = r, maxi = 0, sm = 0;
            ll z = sqrt(y);
            forr(z,1)
            {
                if(y%r==0)
                {
                    maxi = y/r;
                    break;
                }
            }
            if(maxi>k)
            {
                cout<<y;
                flag=false;
                break;
            }
            // vl ax;
            // for(auto x : spf) {
            //     while(y % x == 0) {
            //         ax.push_back(x);
            //         maxi = max(x,maxi);
            //         if(sm == 0) sm = x;
            //         y /= x;
            //     }
            //     if(y==1)
            //         break;
            // }
            // if(y>1)
            // {
            //     ax.push_back(y);
            //     maxi = max(maxi,y);
            // }
            // ll ma = 1;
            // fori(0,((ax.size()+1)/2)) {
            //     ma *= ax[i];
            // } 
            // if(maxi > k || (n / ma > k) || (ma > k)) {
            //     cout << r;
            //     flag = false;
            //     break;
            // }
        }
        if(flag) cout << -1;
        nl;
    }
    return 0;
}
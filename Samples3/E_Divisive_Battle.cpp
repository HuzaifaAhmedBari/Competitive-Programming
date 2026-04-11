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

vl spf;
void build_spf(ll n) {
    spf.assign(n + 1, 0);
    iota(spf.begin(), spf.end(), 0LL);
    for (ll i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vl factorize(ll x) {
    vl factors;
    while (x > 1) {
        factors.push_back(spf[x]);
        ll z = spf[x];
        while(x%z==0)
            x/=z;
    }
    return factors;
}

int main()
{
    io;
    ll t = 1;
    cin>>t;
    build_spf(1e6+1);
    while(t--)
    {
        ll n;
        cin>>n;
        vl arr(n);
        cin>>arr;
        if(is_sorted(all(arr)))
        {
            cout<<"Bob";
            nl;
            continue;
        }
        bool flag=false;
        ll largest = -1;
        fori(0,n)
        {
            vl temp = factorize(arr[i]);
            if(temp.empty() or temp.back()==arr[i])
            {
                if(i!=0)
                {
                    if(arr[i]<largest)
                    {
                        flag=true;
                        break;
                    }
                }
            }
            else
            {
                if(temp.front()<temp.back())
                {
                    flag=true;
                    break;
                }
            }
            largest = ((temp.empty())?1LL:temp.front());
        }
        if(flag)
            cout<<"Alice";
        else
            cout<<"Bob";
        nl;
    }
    return 0;
}
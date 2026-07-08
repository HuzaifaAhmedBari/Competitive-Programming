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

// 0 is even, 1 is odd
array<vector<ll>, 2> manacher(const vl &s) {
    ll n = s.size();
    array<vector<ll>, 2> p = {vector<ll>(n + 1), vector<ll>(n)};
    for (ll z = 0; z < 2; ++z)
        for (ll i = 0, l = 0, r = 0; i < n; i++) {
            ll t = r - i + !z;
            if (i < r) p[z][i] = min(t, p[z][l + t]);
            ll L = i - p[z][i], R = i + p[z][i] - !z;
            while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
                p[z][i]++, L--, R++;
            if (R > r) l = L, r = R;
        }
    return p;
}

int main()
{
    io;
    ll t = 1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        n<<=1LL;
        vl arr(n);
        cin>>arr;
        map<ll,ll> last;
        ll ans = 1;
        fori(0,n)
        {
            last[arr[i]] = i;
        }
        ll l = -1;
        fori(0,n)
        {
            if(arr[i]==0)
            {
                l = i;
                break;
            }
        }
        ll z = l;
        ll r = last[0];
        map<ll,ll> m,m1,m2;
        m[0]++;
        while(l<=r and arr[l]==arr[r])
        {
            m[arr[l]]++;
            l++;
            r--;
        }
        if(l>r)
        {
            l = z-1;
            r = last[0]+1;
            while(l>=0 and r<n and arr[l]==arr[r])
            {
                m[arr[l]]++;
                l--;
                r++;
            }
            fori(0,1e9)
            {
                if(not m.count(i))
                {
                    ans = i;
                    break;
                }
            }
        }
        l = z;
        r = l;
        while(l>=0 and r<n and arr[l]==arr[r])
        {
            m1[arr[l]]++;
            l--;
            r++;
        }
        fori(0,1e9)
        {
            if(not m1.count(i))
            {
                ans = max(ans,i);
                break;
            }
        }
        l = last[0];
        r = l;
        while(l>=0 and r<n and arr[l]==arr[r])
        {
            m2[arr[l]]++;
            l--;
            r++;
        }
        fori(0,1e9)
        {
            if(not m2.count(i))
            {
                ans = max(ans,i);
                break;
            }
        }
        cout<<ans;
        nl;
    }
    return 0;
}
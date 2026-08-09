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

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n = 0) {
        init(n);
    }

    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }

    // add delta at index i (0-based)
    void update(int i, long long delta) {
        for (++i; i <= n; i += i & -i)
            bit[i] += delta;
    }

    // prefix sum [0..i]
    long long query(int i) {
        long long s = 0;
        for (++i; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    // sum in [l..r]
    long long rangeQuery(int l, int r) {
        if (l > r) return 0;
        return query(r) - (l ? query(l - 1) : 0);
    }

    // find smallest index with prefix sum >= k
    // assumes all frequencies are non-negative
    int kth(long long k) {
        int pos = 0;
        long long sum = 0;
        int logn = 31 - __builtin_clz(n);
        for (int i = 1 << logn; i > 0; i >>= 1) {
            if (pos + i <= n && sum + bit[pos + i] < k) {
                sum += bit[pos + i];
                pos += i;
            }
        }
        return pos; // 0-based index
    }
};

int main()
{
    io;
    ll t = 1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vl arr(n);
        cin>>arr;
        vl sufsum(n), sufmax(n), sum(n), premax(n);
        sufsum[n-1] = arr[n-1];
        sufmax[n-1] = n-1;
        premax[0] = arr[0];
        ll cur = arr[n-1];
        forr(n-2,0)
        {
            sufmax[r] = sufmax[r+1];
            if(arr[r]>cur)
            {
                cur = arr[r];
                sufmax[r] = r;
            }
        }
        forr(n-2,0)
        {
            sufsum[r] = sufsum[r+1]+arr[r];
        }
        fori(1,n)
            premax[i] = max(premax[i-1],arr[i]);
        ll mx = arr[0];
        fori(0,n)
        {
            if(i)
                sum[i] = sum[i-1];
            sum[i]+=max(0LL,mx-arr[i]);
            mx = max(mx,arr[i]);
        }
        ll ans = sum[n-1];
        set<ll> s(all(arr));
        map<ll,ll> m;
        ll z = 0;
        for(auto x:s)
            m[x] = z++;
        Fenwick fre(m.size()+1), ft(m.size()+1);
        ll j = 0;
        while(j<sufmax[1])
        {
            ft.update(m[arr[j]],arr[j]);
            fre.update(m[arr[j++]],1);
        }
        ll after = (arr[sufmax[1]]*(n-sufmax[1]))-sufsum[sufmax[1]];
        ans = min(ans,after);
        fre.update(m[arr[0]],1);
        ft.update(m[arr[0]],arr[0]);
        fori(1,n-1)
        {
            fre.update(m[arr[i-1]],-1);
            ft.update(m[arr[i-1]],-arr[i-1]);
            while(j<sufmax[i+1])
            {
                ft.update(m[arr[j]],arr[j]);
                fre.update(m[arr[j++]],1);
            }
            ll before = sum[i-1];
            if(premax[i-1]<=arr[sufmax[i+1]])
            {
                ll after = (arr[sufmax[i+1]]*(n-sufmax[i+1]))-sufsum[sufmax[i+1]];
                ll cur = (premax[i-1]*fre.query(m[premax[i-1]]))-ft.query(m[premax[i-1]]);
                ans = min(ans,before+cur+after);
            }
            else
            {
                ll cur = ((premax[i-1]*(n-i-1))-sufsum[i+1]);
                ans = min(ans,before+cur);
            }
        }
        cout<<ans;
        nl;
    }
    return 0;
}
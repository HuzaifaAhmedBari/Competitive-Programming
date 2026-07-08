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

int main()
{
    io;
    ll t = 1;
    cin>>t;
    while(t--)
    {
        ll l1=0,l2=0,l3=0,r1=0,r2=0,r3=0;
        ll a=0,b=0,c=0;
        ll n;
        cin>>n;
        vl arr(n);
        cin>>arr;
        while(r1<n)
        {
            if(arr[r1]==1)
                a++;
            else
                a--;
            r1++;
            if(a>=0)
                break;
        }
        r2 = r1;
        l2 = r1;
        while(r2<n)
        {
            if(arr[r2]==3)
                b--;
            else
                b++;
            r2++;
            if(b>=0)
                break;
        }
        if(r2<n)
        {
            YES(1);
            nl;
            continue;
        }
        vl suf(n,-1);
        forr(n-2,0)
        {
            suf[r] = suf[r+1];
            if(arr[r]==3)
                suf[r]-=1;
            else
            {
                if(suf[r]<0)
                    suf[r] = 0;
                suf[r]++;
            }
            if(suf[r]<0)
                suf[r] = -1;
        }
        ll z = 0;
        bool f = false;
        fori(0,n-2)
        {
            if(arr[i]==1)
                z++;
            else
                z--;
            if(z>=0 and suf[i+1]>=0)
                f = true;
        }
        YES(f);
        nl;
    }
    return 0;
}
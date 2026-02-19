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
#define YES(expr) (expr)? cout<<"Alice" : cout<<"Bob"
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
        ll n;
        cin>>n;
        string s;
        cin>>s;
        string b = s;
        sahi(b);
        if(s==b)
        {
            YES(0);
            nl;
            continue;
        }
        YES(1);
        nl;
        vl ans;
        fori(0,n)
            if(s[i]!=b[i])
                ans.push_back(i+1);
        cout<<ans.size();
        nl;
        cout<<ans;
        nl;
        // ll mx = 0, count = 0;
        // fori(0,n)
        // {
        //     ll zero = 0, one = 0;
        //     while(i<n and s[i]=='0')
        //         i++;
        //     while(i<n and s[i]=='1')
        //     {
        //         i++;
        //         one++;
        //     }
        //     while(i<n and s[i]=='0')
        //     {
        //         i++;
        //         zero++;
        //     }
        //     mx = max(mx,min(one,zero));
        //     if(min(one,zero)>=1)
        //         count++;
        // }
        // if(!(count&1))
        // {
        //     YES(0);
        //     nl;
        //     continue;
        // }
        // YES(1);
        // nl;
        // ll i = 0;
        // while(i<n and s[i]=='0')
        //     i++;
        // ll x = i+1, cur = 0;
        // while(i<n and s[i]=='1')
        // {
        //     i++;
        //     cur++;
        // }
        // while(i<n and s[i]=='0')
        // {
        //     i++;
        //     cur++;
        // }
        // cout<<cur;
        // nl;
        // cout<<x<<" "<<i;
        // nl;
    }
    return 0;
}
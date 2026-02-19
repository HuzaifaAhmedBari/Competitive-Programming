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
        ll n,m,k;
        cin>>n>>m>>k;
        vl arr1(n), arr2(m);
        cin>>arr1>>arr2;
        string s;
        cin>>s;
        sahi(arr1);
        sahi(arr2);
        vl mini(n,LLONG_MAX);
        min_heap<pii> right, left;
        fori(0,n)
        {
            auto it = lower_bound(all(arr2),arr1[i]);
            if(it!=arr2.end())
                right.push({(*it)-arr1[i],i});
            else
                right.push({LLONG_MAX,i});
            if(it!=arr2.begin())
                left.push({(arr1[i]-(*(it-1))),i});
            else
                left.push({LLONG_MAX,i});
        }
        vb used(n,false);
        ll cur = 0, ans = n;
        fori(0,s.size())
        {
            if(s[i]=='L')
                cur--;
            else
                cur++;
            // cout<<ans<<" "<<cur<<" "<<right.top().fs<<" "<<right.top().sc<<" "<<left.top().fs<<" "<<left.top().sc;
            // nl;
            if(cur>0)
            {
                while(not right.empty() and (used[right.top().sc] or right.top().fs<=cur))
                {
                    if(not used[right.top().sc])
                        ans--;
                    used[right.top().sc]=true;
                    right.pop();
                }
            }
            else
            {
                while(not left.empty() and (used[left.top().sc] or left.top().fs<=-1LL*cur))
                {
                    if(not used[left.top().sc])
                        ans--;
                    used[left.top().sc]=true;
                    left.pop();
                }
            }
            cout<<ans<<" ";
        }
        nl;
    }
    return 0;
}
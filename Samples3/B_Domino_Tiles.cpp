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
#define MOD 998244353
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
#define fori(a,b) for(ll i=a;i<b;i+=2)
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
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll ans = 0;
        bool flag = false;
        bool res = true;
        fori(0,n)
        {
            if(not flag)
            {
                if(i+1==n)
                {
                    if((s[i]=='0' or s[i]=='?'))
                        ;
                    else
                        res = false;
                }
                else
                {
                    if((s[i]=='0' or s[i]=='?') and (s[i+1]=='0' or s[i+1]=='?'))
                        ;
                    else
                        res = false;
                }
            }
            else
            {
                if(i+1==n)
                {
                    if(s[i]=='1' or s[i]=='?')
                        ;
                    else
                        res = false;
                }
                else
                {
                    if((s[i]=='1' or s[i]=='?') and (s[i+1]=='1' or s[i+1]=='?'))
                        ;
                    else
                        res = false;
                }
            }
            flag = !flag;
        }
        if(res)
            ans++;
        res = true;
        flag = false;
         
        if(s[0]=='1' or s[0]=='?')
        {
            fori(1,n)
            {
                if(not flag)
                {
                    if(i+1==n)
                    {
                        if((s[i]=='0' or s[i]=='?'))
                            ;
                        else
                            res = false;
                    }
                    else
                    {
                        if((s[i]=='0' or s[i]=='?') and (s[i+1]=='0' or s[i+1]=='?'))
                            ;
                        else
                            res = false;
                    }
                }
                else
                {
                    if(i+1==n)
                    {
                        if(s[i]=='1' or s[i]=='?')
                            ;
                        else
                            res = false;
                    }
                    else
                    {
                        if((s[i]=='1' or s[i]=='?') and (s[i+1]=='1' or s[i+1]=='?'))
                            ;
                        else
                            res = false;
                    }
                }
                flag = !flag;
            }
            if(res)
                ans++;
            res = false;
        }
         
        flag = false;
        res = true;
        fori(0,n)
        {
            if(flag)
            {
                if(i+1==n)
                {
                    if((s[i]=='0' or s[i]=='?'))
                        ;
                    else
                        res = false;
                }
                else
                {
                    if((s[i]=='0' or s[i]=='?') and (s[i+1]=='0' or s[i+1]=='?'))
                        ;
                    else
                        res = false;
                }
            }
            else
            {
                if(i+1==n)
                {
                    if(s[i]=='1' or s[i]=='?')
                        ;
                    else
                        res = false;
                }
                else
                {
                    if((s[i]=='1' or s[i]=='?') and (s[i+1]=='1' or s[i+1]=='?'))
                        ;
                    else
                        res = false;
                }
            }
            flag = !flag;
        }
        if(res)
            ans++;
        res = true;
        flag = false;
         
        if(s[0]=='0' or s[0]=='?')
        {
            fori(1,n)
            {
                if(flag)
                {
                    if(i+1==n)
                    {
                        if((s[i]=='0' or s[i]=='?'))
                            ;
                        else
                            res = false;
                    }
                    else
                    {
                        if((s[i]=='0' or s[i]=='?') and (s[i+1]=='0' or s[i+1]=='?'))
                            ;
                        else
                            res = false;
                    }
                }
                else
                {
                    if(i+1==n)
                    {
                        if(s[i]=='1' or s[i]=='?')
                            ;
                        else
                            res = false;
                    }
                    else
                    {
                        if((s[i]=='1' or s[i]=='?') and (s[i+1]=='1' or s[i+1]=='?'))
                            ;
                        else
                            res = false;
                    }
                }
                flag = !flag;
            }
            if(res)
                ans++;
            res = false;
        }
        cout<<ans;
        nl;

        
    }
    return 0;
}
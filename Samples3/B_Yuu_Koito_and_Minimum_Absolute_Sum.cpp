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
#define fori(arr,b) for(ll i=arr;i<b;i++)
#define forj(arr,b) for(ll j=arr;j<b;j++)
#define fork(arr,b) for(ll k=arr;k<b;k++)
#define forr(arr,b) for(ll r=arr;r>=b;r--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)

template <typename arr, typename B>
istream& operator>>(istream &in, pair<arr,B> &p) {
    in >> p.first >> p.second;
    return in;
}
template <typename T>
istream& operator>>(istream &in, vector<T> &v) {
    for (auto &x : v) in >> x;
    return in;
}
template <typename arr, typename B>
istream& operator>>(istream &in, vector<pair<arr,B>> &vp) {
    for (auto &p : vp) in >> p.first >> p.second;
    return in;
}

template <typename arr, typename B>
ostream& operator<<(ostream &out, const pair<arr,B> &p) {
    out << p.first << " " << p.second;
    return out;
}
template <typename T>
ostream& operator<<(ostream &out, const vector<T> &v) {
    for (auto &x : v) out << x << " ";
    return out;
}
template <typename arr, typename B>
ostream& operator<<(ostream &out, const vector<pair<arr,B>> &vp) {
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
    for(ll i=5;i*i<=n;i+=6)
    {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}
ll nextprime(ll n)	{ return (isprime(n))? n : nextprime(n+1); }
ll sum_digits(ll n)	{ return (n<10)? n : n%10 + sum_digits(n/10); }
ll gcd(ll arr, ll b)	{ return (b==0)? arr : gcd(b,arr%b); }
ll lcm(ll arr, ll b)	{ return (arr*b)/gcd(arr,b); }
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
        // fori(1,n-1)
        //     if(arr[i]==-1)
        //         arr[i] = 0;
        // ll sum = 0;
        // fori(1,n-2)
        // {
        //     sum+=arr[i+1]-arr[i];
        // }
        // if(arr[0]!=-1 and arr[1]!=-1)
        //     sum+=arr[1]-arr[0];
        // else
        //     sum-=arr[0];
        // if(arr.back()!=-1 and arr[n-2]!=-1)
        //     sum+=arr[n-1]-arr[n-2];
        // else
        //     sum+=arr.back();
        // if(sum==0)
        // {
        //     fori(0,n)
        //         if(arr[i]==-1)
        //             arr[i]=0;
        // }
        // else if(sum>0)
        // {
        //     if(arr.front()==-1)
        //         arr.front() = arr[1]+abs(sum-arr[1]);
        //     else if(arr.back()==-1)
        //         arr.back() = min(0LL,)
        // }
        // cout<<sum;
        ll x = arr[n-1];
        if(x == -1)
        {
            if(arr[0] == -1)
                arr[0] = 0;
            arr[n-1] = arr[0];
        }
        else if(arr[0] == -1)
        {
            arr[0] = x;
        }
        fori(0,n)
        {
            if(arr[i] == -1)
                arr[i] = 0;
        }
        cout << abs(arr[n-1] - arr[0]);
        nl;
        cout << arr;
        nl;
    }
    return 0;
}
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
int main()
{
    io;
    ll t = 1;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll x = n*n;
        if(k==x)
        {
            YES(1);
            nl;
            fori(0,n)
            {
                forj(0,n)
                {
                    cout<<"U";
                }
                nl;
            }
            continue;
        }
        k = x-k;
        if(k<4)
        {
            YES(0);
            nl;
            continue;
        }
        YES(1);
        nl;
        vector<vector<char>> s(n,vector<char>(n,'R'));
        s[0][0] = 'R';
        s[0][1] = 'D';
        s[1][1] = 'L';
        s[1][0] = 'U';
        k-=4;
        queue<pii> q;
        q.push({0,0});
        q.push({0,1});
        q.push({1,0});
        q.push({1,1});
        vpii ds = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<char> put = {'D', 'U', 'R', 'L'};
        vbb visited(n,vb(n,false));
        visited[0][0] = visited[0][1] = visited[1][0] = visited[1][1] = true;
        function<bool(pii)> fine = [&](pii x) {
            return x.fs>=0 and x.fs<=n-1 and x.sc>=0 and x.sc<=n-1 and not visited[x.fs][x.sc];
        };
        while(not q.empty() and k>0)
        {
            pii x = q.front();
            q.pop();
            fori(0,4)
            {
                if(k<=0)
                    break;
                ll dx = x.fs+ds[i].fs;
                ll dy = x.sc+ds[i].sc;
                if(fine({dx,dy}))
                {
                    q.push({dx,dy});
                    visited[dx][dy] = true;
                    s[dx][dy] = put[i];
                    k--;
                }
            }
        }
        fori(0,n)
        {
            forj(0,n)
            {
                cout<<s[i][j];
            }
            nl;
        }
    }
    return 0;
}
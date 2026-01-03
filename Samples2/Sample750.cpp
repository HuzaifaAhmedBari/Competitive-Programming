//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<"\n"
#define re return 0
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
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(ll i=a;i<b;i++)
#define forj(a,b) for(ll j=a;j<b;j++)
#define fork(a,b) for(ll k=a;k<b;k++)
#define forr(a,b) for(ll r=a;r>=b;r--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fork(0,vec.size()) cin>>vec[k]
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
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
        string a,b;
        cin>>a>>b;
        vector<pair<ll,char>> x,y;
        char c = a[0],d;
        if(c=='L')
            d='R';
        else
            d='L';
        ll cc =0,cd=0;
        fori(0,a.size())
        {
            if(a[i]==c)
            {
                cc++;
                if(cd!=0)
                {
                    x.push_back({cd,d});
                }
                cd=0;
            }
            else
            {
                cd++;
                if(cc!=0)
                {
                    x.push_back({cc,c});
                }
                cc=0;
            }
        }
        if(cc!=0)
        {
            x.push_back({cc,c});
        }
        else if(cd!=0)
        {
            x.push_back({cd,d});
        }
        cc=0;cd=0;
        c = b[0];
        if(c=='R')
            d='L';
        else
            d='R';
        fori(0,b.size())
        {
            if(b[i]==c)
            {
                cc++;
                if(cd!=0)
                {
                    y.push_back({cd,d});
                }
                cd=0;
            }
            else
            {
                cd++;
                if(cc!=0)
                {
                    y.push_back({cc,c});
                }
                cc=0;
            }
        }
        if(cc!=0)
        {
            y.push_back({cc,c});
        }
        else if(cd!=0)
        {
            y.push_back({cd,d});
        }
        if(x.size()!=y.size())
        {
            YES(0);
            nl;
            continue;
        }
        bool flag=1;
        fori(0,x.size())
        {
            if(x[i].second != y[i].second or y[i].first<x[i].first or y[i].first>x[i].first*2)
            {
                flag=false;
                break;
            }
        }
        YES(flag);
        nl;
    }
    return 0;
}
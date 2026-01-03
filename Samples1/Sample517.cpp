//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<"\n"
#define re return 0
#define vl vector<ll>
#define vll vector<vector<ll>>
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
    int t = 1;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        ll l1 = count(all(a),'L');
        ll l2= count(all(b),'L');
        ll r1 = count(all(a),'R');
        ll r2 = count(all(b),'R');
        if(l1>l2 || r1>r2)
        {
            YES(0);
            nl;
            continue;
        }
        ll j=0;
        ll x=0,y=0,x2=0,y2=0;
        vector<pair<char,ll>> arr1,arr2;
        char c = a[0];
        char d;
        if(c=='L')
        {
            d='R';
        }
        else{
            d='L';
        }
        fori(0,a.size())
        {
            if(a[i]==c)
            {
                x++;
                if(y!=0)
                    arr1.push_back({d,y});
                y=0;
            }
            else
            {
                if(x!=0)
                    arr1.push_back({c,x});
                x=0;
                y++;
            }
        }
        if(x>0)
            arr1.push_back({c,x});
        else if(y>0)
            arr1.push_back({d,y});
        x=0;y=0;
        fori(0,b.size())
        {
            if(b[i]==c)
            {
                x++;
                if(y!=0)
                    arr2.push_back({d,y});
                y=0;
            }
            else
            {
                if(x!=0)
                    arr2.push_back({c,x});
                x=0;
                y++;
            }
        }
        if(x>0)
            arr2.push_back({c,x});
        else if(y>0)
            arr2.push_back({d,y});
        x=0;y=0;
        if(arr1.size()!=arr2.size())
        {
            YES(0);
            nl;
            continue;
        }
        bool flag=true;
        fori(0,arr1.size())
        {
            if(arr2[i].second>arr1[i].second*2 || arr1[i].second>arr2[i].second || arr1[i].first!=arr2[i].first)
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
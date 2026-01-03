//EK Maqsad Pora Hwa Ab Maqsad 2 Nahi Bhoolna
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
ll nextprime(ll n) {
    return (isprime(n))? n : nextprime(n+1);
}
ll sum_digits(ll n) {
    return (n<10)? n : n%10 + sum_digits(n/10);
}
ll gcd(ll a, ll b) {
    return (b==0)? a : gcd(b,a%b);
}
ll lcm(ll a, ll b) {
    return (a*b)/gcd(a,b);
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
int main()
{
    io;
    int t = 1;
    //cin>>t;
    while(t--)
    {
        string s, t;
        cin >> s >> t;
        ll n = s.size(), k = t.size();
        vl ans;
        string s2 = s, t2 = t;
        fori(0,n) s2[i] = tolower(s2[i]);
        fori(0,k) t2[i] = tolower(t2[i]);
        vl pi(k, 0);
        ll j = 0;
        fori(1,k) {
            while (j > 0 && !(t2[i] == t2[j] || t2[i] == '?' || t2[j] == '?')) j = pi[j - 1];
            if (t2[i] == t2[j] || t2[i] == '?' || t2[j] == '?') j++;
            pi[i] = j;
        } j = 0;
        fori(0,n) {
            while (j > 0 && !(t2[j] == '?' || t2[j] == s2[i])) j = pi[j - 1];
            if (t2[j] == '?' || t2[j] == s2[i]) j++;
            if (j == k) {
                ans.push_back(i - k + 1);
                j = pi[j - 1];
            }
        }
        cout << ans.size(); nl;
        print(ans);
        nl;
    }
    re;
}
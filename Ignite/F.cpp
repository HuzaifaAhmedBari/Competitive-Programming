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
        int n;
        double r;
        cin >> n >> r;
        vector<pair<double, double>> a(n);
        fori(0,n) {
            cin >> a[i].first >> a[i].second;
        }
        vector<pair<double, double>> b;
        fori(0,n) {
            double x = a[i].first, y = a[i].second;
            double d = sqrt(x * x + y * y);
            if (d <= r) {
                cout << fixed << setprecision(6) << 0.0;nl;
                return 0;
            }
            double a1 = atan2(y, x);
            double a2 = asin(r / d);
            double left = a1 - a2;
            double right = a1 + a2;
            if (left < 0) left += 2 * M_PI;
            if (right < 0) right += 2 * M_PI;
            if (right >= 2 * M_PI) right += 2 * M_PI;
            if (left >= 2 * M_PI) left -= 2 * M_PI;
            if (right < left) {
                b.emplace_back(left, 2 * M_PI);
                b.emplace_back(0, right);
            } else {
                b.emplace_back(left, right);
            }
        }
        sahi(b);
        vector<pair<double, double>> mp;
        for (auto c : b) {
            if (mp.empty() || c.first > mp.back().second + 1e-12) {
                mp.push_back(c);
            } else {
                mp.back().second = max(mp.back().second, c.second);
            }
        }
        double maxi = 0.0;
        if (!mp.empty()) {
            maxi = mp[0].first + (2 * M_PI - mp.back().second);
            fori(0,mp.size()) {
                double gap = mp[i].first - mp[i - 1].second;
                maxi = max(maxi, gap);
            }
        }
        double ans = maxi * 180.0 / M_PI;
        if (ans < 1e-6) ans = 0.0;
        cout << fixed << setprecision(6) << ans;nl;
    }
    re;
}
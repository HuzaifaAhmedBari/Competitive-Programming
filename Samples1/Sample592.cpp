// Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<"\n"
#define re return 0
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define all(vec) vec.begin(), vec.end()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)

bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    io;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        vl a(n), b(n);
        input(a);
        input(b);
        ll fxd = -1;
        bool flag = false;
        fori(0, n) {
            if(b[i] != -1) {
                ll psblx = a[i] + b[i];
                if(fxd == -1) fxd = psblx;
                else if(fxd != psblx) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) {
            cout << 0;
            nl;
            continue;
        }
        ll maxi = 0, mini = 1e18;
        fori(0, n)
        {
            if(b[i] == -1)
            {
                maxi = max(maxi, a[i]);
                mini = min(mini, a[i] + k);
            }
        }
        if(fxd != -1)
        {
            if(fxd >= maxi && fxd <= mini)
                cout << 1;
            else
                cout << 0;
            nl;
        } 
        else
        {
            if(maxi > mini) cout << 0;
            else cout << mini - maxi + 1;
            nl;
        }
    }
    re;
}
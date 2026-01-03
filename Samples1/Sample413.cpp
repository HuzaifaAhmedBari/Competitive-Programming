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
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int t = 1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        ll a12=0,a11=0,b02=0,b01=0;
        fori(0,n)
        {
            if(i&1)
            {
                if(a[i]=='1')
                {
                    a12++;
                }
                if(b[i]=='0')
                {
                    b02++;
                }
            }
            else
            {
                if(a[i]=='1')
                {
                    a11++;
                }
                if(b[i]=='0')
                {
                    b01++;
                }
            }
        }
        YES(b02>=a11 && b01>=a12);
        nl;
    }
    return 0;
}
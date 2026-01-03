//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<endl
#define re return 0
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define yesno(expr) (expr)? cout<<"Yes" : cout<<"No"
#define Yesno(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int t = 1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n%4==0)
        {
            cout<<"YES";
            nl;
            ll sum1=0,sum2=0;
            for(ll i=2;i<=n;i+=2)
            {
                cout<<i<<" ";
                sum1+=i;
            }
            ll i;
            for(i=1;i<n-1;i+=2)
            {
                cout<<i<<" ";
                sum2+=i;
            }
            cout<<sum1-sum2;
            nl;
        }
        else
        {
            cout<<"NO";
            nl;
        }
    }
    return 0;
}
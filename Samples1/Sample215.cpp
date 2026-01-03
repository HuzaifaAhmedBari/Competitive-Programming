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
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int t = 1;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        if(n<k)
        {
            cout<<n;
            nl;
            continue;
        }
        if(n==k)
        {
            cout<<1;
            nl;
            continue;
        }
        if(k==1)
        {
            cout<<n;
            nl;
            continue;
        }
        ll temp=0,i=1,count=0;
        while(n>=k)
        {
            temp=0;
            i=1;
            while(temp<=n)
            {
                i++;
                temp = pow(k,i);
            }
            i--;
            n-=pow(k,i);
            count++;
        }
        cout<<n+count;
        nl;
    }
    return 0;
}
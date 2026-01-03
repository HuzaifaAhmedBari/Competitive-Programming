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
int main()
{
    io;
    int n;
    cin>>n;
    vl arr(n);
    ll ans=1,a=0;
    fori(0,n)
    {
        cin>>arr[i];
        if(arr[i]!=0)
            ans *= arr[i];
        else
            a++;
    }
    if(a==n)
    {
        fori(0,n-1)
        {
            cout<<"0 ";
        }
        cout<<0;
        nl;
        re;
    }
    ll sol;
    fori(0,n)
    {
        if(arr[i]!=0)
            sol = ans/arr[i];
        else
            sol = ans;
        if(i==n-1)
        {
            cout<<sol;
            break;
        }
        cout<<sol<<" ";
    }
    nl;
    return 0;
}
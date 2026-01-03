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
    int n,k;
    cin>>n>>k;
    vl arr(n);
    fori(0,n)
    {
        cin>>arr[i];
    }
    ll mini = LLONG_MAX;
    ll sum=0;
    for(int i=0;i<n-k;i++)
    {
        sum=arr[i]+arr[i+k];
        mini=min(sum,mini);
    }
    if(mini==LLONG_MAX)
    {
        mini=arr[0]+arr[n-1];
    }
    cout<<mini;
    nl;
    return 0;
}
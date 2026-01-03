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
    ll a,b,c;
    cin>>a>>b>>c;
    ll a5 = a%5;
    ll a7 = a%7;
    ll b5 = b%5;
    ll b7 = b%7;
    ll c5 = c%5;
    ll c7 = c%7;
    if(a5==0 && b5==0 && c7==0) cout<<"YES";
    else if(a5==0 && b7==0 && c5==0)    cout<<"YES";
    else if(a7==0 && b5==0 && c5==0)    cout<<"YES";
    else    cout<<"NO";
    nl;
    return 0;
}
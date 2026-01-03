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
#define Sh ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    string a;
    cin>>a;
    ll a0=0,a1=0;
    ll max1=-1,max0=-1;
    fori(0,a.size())
    {
        if(a[i]=='0')
        {
            a0++;
            max1=max(max1,a1);
            a1=0;
        }
        else if(a[i]=='1')
        {
            a1++;
            max0=max(max0,a0);
            a0=0;
        }
    }
    max0=max(max0,a0);
    max1=max(max1,a1);
    YES(max0>=7 || max1>=7);
    nl;
    return 0;
}

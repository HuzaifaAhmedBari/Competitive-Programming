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
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    ll n,k;
    cin>>n>>k;
    if(n%2)
    {
        ll temp = ceil(n/2);
        if(k<=temp+1)
        {
            cout<<(1+(k-1)*2);
            nl;
            re;
        }
        else
        {
            cout<<(2+(k-2-temp)*2);
            nl;
            re;
        }
    }
    else
    {
        ll temp = ceil(n/2);
        if(k<=temp)
        {
            cout<<(1+(k-1)*2);
            nl;
            re;
        }
        else
        {
            cout<<(2+(k-1-temp)*2);
        }
    }
    return 0;
}
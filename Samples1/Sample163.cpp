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
    ll t;
    cin>>t;
    ll a,b;
    vi fre(1000, 0);
    fori(0,t)
    {
        cin>>a>>b;
        if(i+1 != b)
        {
            fre[b-1]++;
        }
    }
    ll count=0;
    fori(0,1000)
    {
        if(fre[i]>0)
        {
            count++;
        }
    }
    cout<<t-count<<endl;
    return 0;
}
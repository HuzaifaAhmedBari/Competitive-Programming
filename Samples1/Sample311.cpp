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
    int n,m;
    cin>>n>>m;
    vi req(m);
    input(req);
    vii arr(n,vi(m));
    fori(0,n)
    {
        forj(0,m)
        {
            cin>>arr[i][j];
        }
    }
    vi ans(m,0);
    fori(0,m)
    {
        forj(0,n)
        {
            ans[i] += arr[j][i];
        }
    }
    fori(0,m)
    {
        if(ans[i]<req[i])
        {
            cout<<"No";
            nl;
            re;
        }
    }
    cout<<"Yes";
    nl;
    return 0;
}
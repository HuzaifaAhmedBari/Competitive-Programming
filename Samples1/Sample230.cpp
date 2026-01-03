//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
#include <functional>
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
    int n,m;
    cin>>n>>m;
    vbb arr(n+2, vb(m+2,false));
    char temp;
    fori(1,n+1)
    {
        forj(1,m+1)
        {
            cin>>temp;
            if(temp == '.')
            {
                arr[i][j] = true;
            }
        }
    }
    function<void(int,int)> dfs = [&](int i,int j)
    {
        arr[i][j] = false;
        if(arr[i][j+1])
            dfs(i,j+1);
        if(arr[i+1][j])
            dfs(i+1,j);
        if(arr[i][j-1])
            dfs(i,j-1);
        if(arr[i-1][j])
            dfs(i-1,j);
    };
    ll count=0;
    fori(1,n+1)
    {
        forj(1,m+1)
        {
            if(arr[i][j])
            {
                count++;
                dfs(i,j);
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
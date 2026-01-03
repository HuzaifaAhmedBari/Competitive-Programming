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
    vii arr(3, vi(3));
    vi fre(100,0);
    fori(0,3)
    {
        forj(0,3)
        {
            cin>>arr[i][j];
            fre[arr[i][j]]=arr[i][j];
        }
    }
    ll n;
    cin>>n;
    ll temp=0;
    fori(0,n)
    {
        cin>>temp;
        fre[temp]=-1;
    }
    if(fre[arr[0][0]] == fre[arr[0][1]] && fre[arr[0][2]] == -1)
    {
        cout<<"Yes";
        nl;
        re;
    }
    if(fre[arr[1][0]] == fre[arr[1][1]] && fre[arr[1][2]] == -1)
    {
        cout<<"Yes";
        nl;
        re;
    }
    if(fre[arr[2][0]] == fre[arr[2][1]] && fre[arr[2][2]] == -1)
    {
        cout<<"Yes";
        nl;
        re;
    }
    if(fre[arr[0][0]] == fre[arr[1][0]] && fre[arr[2][0]] == -1)
    {
        cout<<"Yes";
        nl;
        re;
    }
    if(fre[arr[0][1]] == fre[arr[1][1]] && fre[arr[2][1]] == -1)
    {
        cout<<"Yes";
        nl;
        re;
    }
    if(fre[arr[0][2]] == fre[arr[1][2]] && fre[arr[2][2]] == -1)
    {
        cout<<"Yes";
        nl;
        re;
    }
    if(fre[arr[0][0]] == fre[arr[1][1]] && fre[arr[2][2]] == -1)
    {
        cout<<"Yes";
        nl;
        re;
    }
    if(fre[arr[0][2]] == fre[arr[1][1]] && fre[arr[2][0]] == -1)
    {
        cout<<"Yes";
        nl;
        re;
    }
    cout<<"No";
    nl;
    return 0;
}
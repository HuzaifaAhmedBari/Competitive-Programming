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
    char a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ra = abs(int(a-b));
    ll la = abs(int(c-d));
    if(ra==1 && (la == 1 || la == 4))
    {
        cout<<"Yes";
        nl;
    }
    else if(ra==2 && (la == 2 || la == 3))
    {
        cout<<"Yes";
        nl;
    }
    else if(ra==3 && (la == 3 || la == 2))
    {
        cout<<"Yes";
        nl;
    }
    else if(ra==4 && (la == 4 || la == 1))
    {
        cout<<"Yes";
        nl;
    }
    else{
    cout<<"No";
    nl;
    }
    return 0;
}
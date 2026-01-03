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
    int d1,m1,y1,d2,m2,y2;
    cin>>d1>>m1>>y1>>d2>>m2>>y2;
    if(y2<y1)
    {
        cout<<10000;
        nl;
        re;
    }
    else if(y2>y1)
    {
        cout<<0;
        nl;
    }
    else if(m2<m1)
    {
        cout<<500*(m1-m2);
        nl;
        re;
    }
    else if(m2>m1)
    {
        cout<<0;
        nl;
    }
    else if(d2<d1)
    {
        cout<<15*(d1-d2);
        nl;
        re;
    }
    else
    {
        cout<<0;
        nl;
        re;
    }
    return 0;
}
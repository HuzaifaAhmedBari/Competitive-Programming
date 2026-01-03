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
    string a,b;
    cin>>a>>b;
    if(a.size()!=b.size())
    {
        cout<<"NO";
        nl;
        re;
    }
    ll count=0;
    ll index1=-1,index2=-1;
    fori(0,a.size())
    {
        if(a[i]!=b[i])
        {
            count++;
            if(count==1)
            {
                index1=i;
            }
            else if(count==2)
            {
                index2=i;
            }
        }
    }
    if(count>2)
    {
        cout<<"NO";
        nl;
        re;
    }
    YES(a[index1] == b[index2] && a[index2] == b[index1]);
    nl;
    return 0;
}
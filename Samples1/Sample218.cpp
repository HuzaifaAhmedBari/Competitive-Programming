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
    string a;
    cin>>a;
    int n = a.size();
    vi fre1(n+n,0),fre2(n+n,0),fre3(n+n,0);
    fori(0,a.size())
    {
        if(a[i]=='A')
        {
            fre1[i]=1;
        }
        else if(a[i]=='B')
        {
            fre2[i]=1;
        }
        else if(a[i]=='C')
        {
            fre3[i]=1;
        }
    }
    ll count=0;
    fori(0,n-2)
    {
        if(fre1[i]==1)
        {
            forj(i+1,n)
            {
                if(fre2[j]==1)
                {
                    if(fre3[j-i+j]==1)
                    {
                        count++;
                    }
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
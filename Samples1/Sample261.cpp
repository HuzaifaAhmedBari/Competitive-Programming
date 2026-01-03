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
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    vll fre(n,vl(26,1));
    vl fre2(n,1);
    vl fre3(26,0);
    fori(0,n)
    {
        cin>>a[i];
        forj(0,a[i].size())
        {
            fre[i][a[i][j]-'a'] = 0;
            fre3[a[i][j]-'a']=1;
        }
    }
    char c;
    ll count=n;
    fori(0,m)
    {
        cin>>c;
        if(fre3[c-'a']==1)
        {
        if(count==0)
        {
            cout<<0<<endl;
            continue;
        }
        forj(0,n)
        {
            if(fre[j][c-'a']==0 && fre2[j]==1)
            {    count--;
                fre2[j]=0;
            }
        }
    }
        cout<<count<<endl;
    }
    return 0;
}
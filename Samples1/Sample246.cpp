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
    int t = 1;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        if(a.size()==1)
        {
            cout<<0;
            nl;
            continue;
        }
        int low=-1,high=-1;
        fori(0,a.size())
        {
            if(a[i]=='1')
            {
                low = i;
                break;
            }
        }
        forr(a.size()-1,0)
        {
            if(a[i]=='1')
            {
                high=i;
                break;
            }
        }
        ll count=0;
        if(low==-1 || high == -1)    cout<<0;
        else
        {
            fori(low,high)
            {
                if(a[i]=='0')   count++;
            }
            cout<<count;
        }
        nl;
    }
    return 0;
}
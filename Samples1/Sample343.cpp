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
    int n;
    cin>>n;
    vl arr(n);
    input(arr);
    ll ans1=0,ans2=0;
    int j=n-1;
    bool flag=true;
    fori(0,n)
    {
        if(i>j)
        {
            break;
        }
        if(arr[i]>arr[j])
        {
            if(flag)
            {
                ans1+=arr[i];
                flag=!flag;
            }
            else
            {
                ans2+=arr[i];
                flag=!flag;
            }
        }
        else
        {
            if(flag)
            {
                ans1+=arr[j];
                i--;
                j--;
                flag=!flag;
            }
            else
            {
                ans2+=arr[j];
                j--;
                i--;
                flag=!flag;
            }
        }
    }
    cout<<ans1<<" "<<ans2;
    nl;
    return 0;
}
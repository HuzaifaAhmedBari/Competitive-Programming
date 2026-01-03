//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<"\n"
#define re return 0
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define us unordered_set<ll>
#define all(vec) vec.begin(), vec.end()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(ll i=a;i<b;i++)
#define forj(a,b) for(ll j=a;j<b;j++)
#define fork(a,b) for(ll k=a;k<b;k++)
#define forr(a,b) for(ll r=a;r>=b;r--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fork(0,vec.size()) cin>>vec[k]
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
void f(vl &arr, vl &ans)
{
    ll j=0,k=arr.size()-1;
    bool flag=true;
    fori(0,arr.size())
    {
        if(flag)
        {
            ans[j] = arr[i];
            j++;
            flag=!flag;
        }
        else
        {
            ans[k]=arr[i];
            k--;
            flag=!flag;
        }
    }
}
int main()
{
    io;
    int t = 1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vl arr(n);
        input(arr);
        sahi(arr);
        vl ans(n);
        f(arr,ans);
        ll sum=0;
        fori(0,n-1)
        {
            sum+=ans[i]+ans[i+1];
        }
        cout<<sum;
        nl;
    }
    return 0;
}
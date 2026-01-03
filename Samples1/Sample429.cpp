//Maqsad Nahi Bhoolna
#include <iostream>
#include <vector>
#include <algorithm>
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
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int a;
    cin>>a;
    forj(0,a)
    {
        int n;
        cin>>n;
        vl arr(n);
        input(arr);
        ll idx1=1,idx2=n;
        ll sum=0;
        ll ans = 0;
        ll t=1;
        fori(0,n)
        {
            sum+=arr[i];
            if(sum<0)
            {
                t = i+2;
                sum = 0;
            }
            if(sum>ans)
            {
                ans = sum;
                idx1 = t;
                idx2 = i+1;
            }
        }
        if(ans == 0)
        {
            ans = *max_element(all(arr));
            idx1 = distance(arr.begin(),max_element(all(arr)))+1;
            idx2 = idx1;
        }
        cout<<"Case "<<j+1<<":";
        nl;
        cout<<ans<<" "<<idx1<<" "<<idx2;
        nl;
        if(j!=a-1)
            nl;
    }
    return 0;
}
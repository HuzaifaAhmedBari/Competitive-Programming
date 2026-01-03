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
int main()
{
    io;
    ll n;
    cin>>n;
    vl arr1(n), arr2(n);
    unordered_map<ll,ll> m1,m2;
    fori(0,n)
    {
        cin>>arr1[i];
        m1[arr1[i]]++;
    }
    fori(0,n)
    {
        cin>>arr2[i];
        m2[arr2[i]]++;
    }
    bool flag=true;
    fori(1,6)
    {
        if(((m1[i]+m2[i])&1))
        {
            flag=false;
            break;
        }
    }
    if(!flag)
    {
        cout<<-1;
        nl;
        re;
    }
    ll ans=0;
    vl array = {(abs(m1[1]-m2[1])>>1LL),(abs(m1[2]-m2[2])>>1LL),(abs(m1[3]-m2[3])>>1LL),(abs(m1[4]-m2[4])>>1LL),(abs(m1[5]-m2[5])>>1LL)};
    ulta(array);
    fori(0,5)
    {
        if(array[i]>0)
        {
            ans+=array[i];
            ll t = array[i];
            forr(4,i+1)
            {
                if(array[r]>=t)
                {
                    array[r] -= t;
                    break;
                }
                else
                {
                    t-=array[r];
                    array[r] -= array[r];
                }
                if(t<=0)
                    break;
            }
        }
    }
    cout<<ans;
    nl;
    return 0;
}
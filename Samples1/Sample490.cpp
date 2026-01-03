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
    int t = 1;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d,n;
        ll ans=0;
        cin>>a>>b>>c>>d>>n;
        
        ll dx = abs(a-c);
        ll dy = abs(b-d);
        ll r = (dx/n);
        ll u = (dy/n);

        // ll t1=dx,t2=dy;
        // ll minmove = min(r,u);
        // ll dz;
        // dx -= minmove*n;
        // dy -= minmove*n;
        // if(dx<0)
        //     dx=0;
        // if(dy<0)
        //     dy=0;

        // if(dy>n)
        // {
        //     ans+=n;
        //     dy-=n;
        //     dz=((max(t1,t2)/n)-(min(t1,t2)));
        // }
        // else
        // {
        //     ans+=dy;
        //     dy=0;
        //     dz=0;
        // }

        // ll mini = min(dx,dy);
        // ll maxi = max(dx,dy);
        // ans += ((minmove * n) <<1LL);
        // ans += mini;

        // cout<<maxi;
        // nl;
        // ll more = (maxi/n);
        // ans += more*n;
        // maxi -= more*n;
        // if(maxi<0)
        //     maxi=0;
        // ans+=maxi;
        // ll z=0;
        // if(dz>0)
        // {
        //     if(dz&1)
        //     {
        //         ans+=dz+1;
        //     }
        //     else
        //     {
        //         ans+=dz;
        //     }
        // }
        ans = 0;
        ans += dx+dy;
        ll dz=0;
        dz = ceil((max(dx,dy)/double(n))) - min(dx,dy) - 1LL;
        if(dz>0)
            ans+=dz+(dz&1);
        cout<<ans;
        nl;
    }
    return 0;
}
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

double root(double n){
    double a =1;
    double lo = min(a, n), hi = max(a, n), mid;
  
    while(100 * lo * lo < n) lo *= 10;
    while(0.01 * hi * hi > n) hi *= 0.1;
  
    for(int i = 0 ; i < 100 ; i++){
      mid = (lo+hi)/2;
      if(mid*mid == n) return mid;
      if(mid*mid > n) hi = mid;
      else lo = mid;
    }
    return mid;
  }

  ll pow(ll b){
    return b*b;
  }

int main()
{
    io;
    ld a,b,c;
    cin>>a>>b>>c;
    cout<<fixed<<setprecision(5);
    ld desc = (pow(b)) - (4*a*c);
    if(a==0 && b==0 && c==0)
    {
        cout<<-1;
        nl;
        re;
    }
    if(a==0 && b==0)
    {
        cout<<0;
        nl;
        re;
    }
    if(a==0)
    {
        cout<<1<<endl;
        ld ans = (-c)/b;
        cout<<ans;
        nl;
        re;
    }
    if(desc<0)
    {
        cout<<0;
        nl;
        re;
    }
    if(desc==0)
    {
        cout<<1<<endl;
        ld ans = (-b)/((2*a));
        cout<<ans;
        nl;
        re;
    }
    ld ans1 = (-b+root(desc))/(2*a);
    ld ans2 = (-b-root(desc))/(2*a);
    if(ans1==ans2)
    {
        cout<<1<<endl;
        cout<<ans1;
        nl;
        re;
    }
    cout<<2<<endl;
    if(ans1<ans2)
    {
        cout<<ans1<<endl;
        cout<<ans2;
    }
    else
    {
        cout<<ans2<<endl;
        cout<<ans1;
    }
    nl;
    return 0;
}
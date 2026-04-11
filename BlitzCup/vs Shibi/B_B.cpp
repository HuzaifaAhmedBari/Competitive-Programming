//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define nl cout<<"\n"
#define vl vector<ll>
#define all(vec) vec.begin(), vec.end()
#define fori(a,b) for(ll i=a;i<b;i++)
#define forj(a,b) for(ll j=a;j<b;j++)
#define forr(a,b) for(ll r=a;r>=b;r--)
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)

template <typename A, typename B>
istream& operator>>(istream &in, pair<A,B> &p) {
    in >> p.first >> p.second;
    return in;
}
template <typename T>
istream& operator>>(istream &in, vector<T> &v) {
    for (auto &x : v) in >> x;
    return in;
}

template <typename A, typename B>
ostream& operator<<(ostream &out, const pair<A,B> &p) {
    out << p.first << " " << p.second;
    return out;
}
template <typename T>
ostream& operator<<(ostream &out, const vector<T> &v) {
    for (auto &x : v) out << x << " ";
    return out;
}

int main()
{
    io;
    ll t = 1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        bool flag=false;
        if(not (n&1))
        {
            n>>=1LL;
            if(n!=m)
                flag=true;
            n<<=1LL;
        }
        if(not (m&1))
        {
            m>>=1LL;
            if(n!=m)
                flag=true;
        }
        YES(flag);
        nl;
    }
    return 0;
}
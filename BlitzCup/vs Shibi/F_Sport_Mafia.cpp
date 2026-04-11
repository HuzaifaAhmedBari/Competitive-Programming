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
    ll n,m;
    cin>>n>>m;
    ll l=0,r=n;
    while(l<=r)
    {
        ll mid = l+(r-l)/2;
        ll z = n-mid;
        ll x = ((z)*(z+1))/2;
        if(x-mid==m)
        {
            cout<<mid;
            nl;
            break;
        }
        else if(x-mid>m)
            l = mid+1;
        else
            r = mid-1;
    }
    nl;
    return 0;
}
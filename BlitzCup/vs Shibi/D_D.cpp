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
        ll n;
        cin>>n;
        vl arr(n);
        cin>>arr;
        if(not(n&1))
        {
            cout<<2;
            nl;
            cout<<"1 "<<n;
            nl;
            cout<<"1 "<<n;
            nl;
            continue;
        }
        cout<<5;
        nl;
        cout<<"1 "<<n;
        nl;
        cout<<"1 "<<3;
        nl;
        cout<<"1 "<<2;
        nl;
        cout<<"2 "<<3;
        nl;
        cout<<"2 "<<n;
        nl;
    }
    return 0;
}
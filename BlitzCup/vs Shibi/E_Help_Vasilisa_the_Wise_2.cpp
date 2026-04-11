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
    ll r1,r2,c1,c2,d1,d2;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    bool flag=false;
    fori(1,10)
    {
        forj(1,10)
        {
            if(i==j)
                continue;
            for(ll k=1;k<=9;k++)
            {
                if(k==j or k==i)
                    continue;
                for(ll z=1;z<=9;z++)
                {
                    if(z==k or z==j or z==i)
                        continue;
                    if(i+j==r1 and k+z==r2 and i+k==c1 and j+z==c2 and i+z==d1 and j+k==d2)
                    {
                        flag=true;
                        cout<<i<<" "<<j;
                        nl;
                        cout<<k<<" "<<z;
                        nl;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(flag)
            break;
    }
    if(not flag)
    {
        cout<<-1;
        nl;
    }
    
    return 0;
}
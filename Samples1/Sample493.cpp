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
    string a;
    cin>>a;
    ll n4=0,n7=0;
    fori(0,a.size())
    {
        if(a[i]=='4')
            n4++;
        else if(a[i]=='7')
            n7++;
    }
    if(n4==n7 && n4==(a.size()+1)/2 && n7==(a.size()+1)/2)
    {
        cout<<a;
        nl;
        re;
    }
    if(a.size()&1)
    {
        fori(0,(a.size()+1)/2)
            cout<<4;
        fori(0,(a.size()+1)/2)
        {
            cout<<7;
        }
        nl;
        re;
    }
    if(a[0]>'7')
    {
        a+='0';
        if(a.size()&1)
        {
            a+='0';
        }
        fori(0,a.size()/2)
        {
            cout<<4;
        }
        fori(0,a.size()/2)
        {
            cout<<7;
        }
        nl;
        re;
    }
    if(a[0]=='4' && a[1]>='4')
    {
        a[1]='7';
    }
    bool flag=false;
    ll foundless=0;
    fori(0,a.size()+1/2)
    {
        if(a[i]>='4')
            continue;
        if(a[i]<'4')
        {
            flag=true;
            a[i]='4';
            foundless = i;
            break;
        }
    }
    if(flag)
    {
        if(a.size()&1)
        {
            a+='0';
        }
        ll a4 = (a.size()/2) - 1;
        ll a7 = a.size()/2;
        fori(0,foundless)
        {
            if(a[i]=='4')
            {
                a4--;
                continue;
            }
            else if(a[i]=='7')
            {
                a7--;
                continue;
            }
            if(a4>0)
            {
                a[i]='4';
                a4--;
            }
            else if(a7>0)
            {
                a[i]='7';
                a7--;
            }
        }
        fori(foundless+1,a.size())
        {
            if(a4>0)
            {
                a[i]='4';
                a4--;
            }
            else if(a7>0)
            {
                a[i]='7';
                a7--;
            }
        }
        cout<<a;
        nl;
        re;
    }
    bool f = false;
    ll found=-1;
    fori(0,a.size()+1/2)
    {
        if(a[i]<'7' && a[i]>'4')
        {
            a[i]='7';
            f = true;
            found=i;
            break;
        }
    }
    if(f)
    {
        if(a.size()&1)
        {
            a+='0';
        }
        ll a4 = a.size()/2;
        ll a7 = (a.size()/2) - 1;
        fori(0,found)
        {
            if(a[i]=='4')
            {
                a4--;
                continue;
            }
            else if(a[i]=='7')
            {
                a7--;
                continue;
            }
            if(a4>0)
            {
                a[i]='4';
                a4--;
            }
            else if(a7>0)
            {
                a[i]='7';
                a7--;
            }
        }
        fori(found+1,a.size())
        {
            if(a4>0)
            {
                a[i]='4';
                a4--;
            }
            else if(a7>0)
            {
                a[i]='7';
                a7--;
            }
        }
        cout<<a;
        nl;
        re;
    }
    else
    {
        a+='0';
        if(a.size()&1)
            a+='0';
        fori(0,a.size()/2)
        {
            cout<<4;
        }
        fori(0,a.size()/2)
        {
            cout<<7;
        }
        nl;
        re;
    }
    return 0;
}
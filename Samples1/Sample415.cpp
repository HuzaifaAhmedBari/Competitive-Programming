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
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define print(vec) for(auto x : vec) cout<<x<<"\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int t = 1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<char> a(n);
        ll l=0,c=0,t=0;
        fori(0,n)
        {
            cin>>a[i];
            if(a[i]=='L')
                l++;
            else if(a[i]=='I')
                c++;
            else
                t++;
        }
        ll ans = max(l,max(c,t));
        l = ans - l;
        c = ans-c;
        t = ans-t;
        vl arr;
        if(a.size()==1)
        {
            cout<<-1;
            nl;
            continue;
        }
        fori(0,a.size()-1)
        {
            if(t>0)
            {
                if((a[i]=='L' && a[i+1]=='I') || (a[i]=='I' && a[i+1]=='L'))
                {
                    a.insert(a.begin()+i+1,'T');
                    t--;
                    arr.push_back(i+1);
                }
            }
            if(l>0)
            {
                if((a[i]=='T' && a[i+1]=='I') || (a[i]=='I' && a[i+1]=='T'))
                {
                    a.insert(a.begin()+i+1,'L');
                    l--;
                    arr.push_back(i+1);
                }
            }
            if(c>0)
            {
                if((a[i]=='L' && a[i+1]=='T') || (a[i]=='T' && a[i+1]=='L'))
                {
                    a.insert(a.begin()+i+1,'I');
                    c--;
                    arr.push_back(i+1);
                }
            }
        }
        cout<<arr.size();
        nl;
        print(arr);
    }
    return 0;
}
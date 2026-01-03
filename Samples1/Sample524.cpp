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
#define all(vec) vec.begin(), vec.end()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    string s;
    cin >> s;
    reverse(all(s));
    string d = "maerd", dr = "remaerd", e = "esare", er = "resare";
    ll i=0;
    while (i < s.size()) {
        if (s.substr(i, 5) == d)
            i += 5;
        else if (s.substr(i, 7) == dr)
            i += 7;
        else if (s.substr(i, 5) == e)
            i += 5;
        else if (s.substr(i, 6) == er)
            i += 6;
        else {
            YES(0);
            nl;
            return 0;
        }
    }
    YES(1);
    nl;
    re;
}
//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
#include <ctype.h>
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
    string a;
    cin>>a;
    ll k;
    cin>>k;
    vi fre;
    int b=0,c;
    fori(0,a.size())
    {
        cout<<i<<endl;
        if(!(isdigit(a[i])))
        {
            int temp = (int(a[i])-'0');
            forj(i,a.size())
            {
                if(!(isdigit(a[j])))
                {
                    temp = temp * 10 + (int(a[j])-'0');
                }
                else
                {
                    break;
                }
            }
            fre.push_back(temp);
            c += temp;
            b++;
        }
    }
    ll req = c/k;
    return 0;
}
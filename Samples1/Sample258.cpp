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
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int n,k;
    cin>>n>>k;
    vector<string> a;
    int t=n;
    fori(0,n)
    {
        string temp;
        cin>>temp;
        a.push_back(temp);
    }
    cout<<a[0].size()<<endl;
    int sum=0;
    fori(0,n)
    {
        if(sum+a[i].size()<=k)
        {
            cout<<a[i]<<" ";
            sum+=a[i].size();
        }
        else
        {
            cout<<endl;
            cout<<a[i]<<" ";
            sum=a[i].size();
        }
    }
    nl;
    return 0;
}
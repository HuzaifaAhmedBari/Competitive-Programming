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
int main()
{
    io;
    int n;
    cin>>n;
    vi arr(n),fre(10000,0);
    fori(0,n)
    {
        cin>>arr[i];
        fre[arr[i]]=1;
    }
    vi arr2;
    forr(n-1,0)
    {
        if(fre[arr[i]])
        {
            arr2.push_back(arr[i]);
            fre[arr[i]]=0;
        }
    }
    cout<<arr2.size();
    nl;
    forr(arr2.size()-1,0)
    {
        cout<<arr2[i]<<" ";
    }
    nl;
    return 0;
}
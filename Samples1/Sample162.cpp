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
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    ll n,k,count=0;
    cin>>n>>k;
    vi arr(n);
    fori(0,n)
    {
        cin>>arr[i];
    }
    fori(0,n-1)
    {
        if(arr[i] + k >= arr[i+1])
        {
            count++;
        }
        else
        {
            count=0;
        }
    }
    if(arr[n-1] - k <= arr[n-2])
    {
        count++;
    }
    if(count == 0)
    {
        count++;
    }
    cout<<count<<endl;
    return 0;
}
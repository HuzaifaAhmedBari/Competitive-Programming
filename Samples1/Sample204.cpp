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
    int t,n;
    cin>>n;
    while(n--)
    {
    cin>>t;
    int index2,index1;
    int maxi=INT_MIN,maxj=INT_MIN;
    vi arr1(t), arr2(t);
    fori(0,t)
    {
        cin>>arr1[i];
        if(arr1[i]>maxj)
        {
            maxj= arr1[i];
            index1=i;
        }
    }
    fori(0,t)
    {
        cin>>arr2[i];
        if(arr2[i]>maxi)
        {
            maxi= arr2[i];
            index2=i;
        }
    }
    int count1=0;
    int count2=0;
    ll ans=0;
    fori(0,t)
    {
        if(arr1[i]>=arr2[i])
        {
            ans+=arr1[i];
        }
    }
    fori(0,t)
    {
        if(arr2[i]>arr1[i])
        {
            ans+=arr2[i];
        }
    }
    int temp=max(maxi,maxj);
    if(temp==maxi)
    {
        ans+=arr1[index2];
    }
    else
    {
        ans+=arr2[index1];
    }
    cout<<ans;
    nl;
}
    return 0;
}
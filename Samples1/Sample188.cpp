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
    int n,k;
    cin>>n>>k;
    vector<pair<char,int>> pii(26);
    fori(0,26)
    {
        pii[i] = {'A'+ i,0};
    }
    char temp;
    fori(0,n)
    {
        cin>>temp;
        int sum = pii[temp-'A'].second;
        pii[temp-'A'] = {temp-'A',sum+1};
    }
    sahi(pii);
    int i=0;
    ll ans=0;
        int sum = pii[i].second;
        if(sum<=k)
        {
            ans += sum*sum;
            k-=sum;
        }
        else
        {
            ans += k*sum;
            k-=k;
        }
        if(k>0)
        {
            ans+=k;
        }
    cout<<ans<<endl;
    return 0;
}
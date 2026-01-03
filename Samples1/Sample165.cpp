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
    int t = 1;
    cin>>t;
    while(t--)
    {
        ll n,k,p;
        cin>>n>>k>>p;
        ll count = 0,ans=0;
        if(k==0)
        {
            cout <<0<< endl;
            continue;
        }
        if(k<0)
        {
            while(n>0 && count > k)
            {
                n--;
                count = count - p;
                ans++;
            }
        }
        if(k>0)
        {
            while(n>0 && count < k)
            {
                n--;
                count += p;
                ans++;
            }
        }
        if((count>=k && k>0) || (count<=k && k<0))
            cout <<ans<< endl;
        else
            cout<<-1<<endl;
    }

    return 0;
}
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
    int n;
    cin>>n;
    vi arr(n);
    ll sum=0;
    fori(0,n)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    ll avg=sum/n;
    ll avg1 = avg-1;
    ll avg2 = avg+1;
    ll sum2=0;
    ll sum3=0;
    ll sum4=0;
    fori(0,n)
    {
        sum2+=pow((arr[i]-avg),2);
        sum3+=pow((arr[i]-avg1),2);
        sum4+=pow((arr[i]-avg2),2);
    }
    cout<<min(sum2,min(sum3,sum4))<<endl;
    return 0;
}
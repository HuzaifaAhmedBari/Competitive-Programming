//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define nl cout<<endl
#define re return 0
#define vi vector<int>
#define vii vector<vector<int>>
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) reverse(vec.begin(),vec.end())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
int main()
{
    io;
    int t = 1;
    cin>>t;
    vi arr(t);
    ll sum1=0,sum2=0;
    int min = INT_MAX;
    fori(0,t)
    {
        cin>>arr[i];
    }
    int j=t-1;
    fori(0,t)
    {
        if(j==i-1)
        {
            break;
        }
        if(sum1>sum2)
        {
            sum2+=arr[j];
            j--;
            i--;
            continue;
        }
        sum1+=arr[i];
        if(j-1<i)
        {
            break;
        }
    }
    
    cout<<abs(sum1-sum2);
    nl;
    return 0;
}
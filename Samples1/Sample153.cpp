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
    int t;
    cin>>t;
    vi arr;
    ll n;
    int c=t;
    cin>>n;
    int base = 10;
    while(c--)
    {
        int ans = n%base;
        arr.push_back(ans);
        n/=10;
    }
    vi arr2 = arr;
    ulta(arr);
    int count=0,count2=0;
    ll sum1=0,sum2=0;
    int j = t-1;
    int base1=1;
    int base2=1;
    cout<<arr[0]<<arr2[0];
    nl;
    fori(0,t)
    {
        if(j==i-1)
        {
            break;
        }
        if(sum1>sum2)
        {
            sum2+=arr2[j];
            j--;
            i--;
            continue;
        }
        sum1+=arr[i];
        count2++;
        if(j-1<i)
        {
            break;
        }
    }
    sum2=0;
    base1=1;
    cout<<sum1+sum2<<endl;
    
    return 0;
}
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
    ll count=0;
    int flag=0,n,m;
    cin>>n>>m;
    vi arr1(n), arr2(m);
    fori(0,n)
    {
        cin>>arr1[i];
    }
    fori(0,m)
    {
        cin>>arr2[i];
    }
    fori(0,m-n+1)
    {
        flag=1;
        forj(0,n)
        {
            if(arr1[j]==arr2[i+j])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            count++;
        }
    }
    cout<<count;
    nl;
    return 0;
}
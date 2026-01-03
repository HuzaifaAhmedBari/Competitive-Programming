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
    int q = 1,n;
    cin>>n>>q;
    vi arr(n,2);
    fori(0,q)
    {
        int a,b;
        cin>>a>>b;
        if(a==1)
        {
            arr[b-1]--;
        }
        else if(a==2)
        {
            arr[b-1]-=2;
        }
        else if(a==3)
        {
            (arr[b-1]>0)? cout<<"No" : cout<<"Yes";
            nl;
        }
    }
    return 0;
}
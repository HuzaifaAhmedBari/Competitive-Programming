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
    int n,m,d,flag=1;
    cin>>n>>m>>d;
    ll count=0;
    vii arr(n, vi(m));
    fori(0,n)
    {
        forj(0,m)
        {
            cin>>arr[i][j];
            if(arr[i][j] % d==0)
            {
                count+= arr[i][j] / d;
            }
            else
            {
                flag=0;
            }
        }
    }
    if(flag)
    cout<<count<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
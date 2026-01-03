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
    int n,m;
    cin>>n>>m;
    vi fre(n,0);
    int temp;
    fori(0,m)
    {
        cin>>temp;
        fre[temp-1]++;
        cin>>temp;
    }
    int max = INT_MIN;
    fori(0,n)
    {
        max = (fre[i]>max)? fre[i] : max;
    }
    cout<<max;
    nl;
    
    return 0;
}
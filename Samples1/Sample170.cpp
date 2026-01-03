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
        ll n,x,k,count=0,i,j;
        cin>>n>>x>>k;
        string a;
        cin>>a;
        if(x==-1)
        {
            if(a[0]=='R' && a[1]=='L')
            {
                if(k%2)
                    cout<<k/2 + 1;
                else
                    cout<<k/2;
                nl;
                continue;
            }
        }
        if(x==1)
        {
            if(a[0]=='L' && a[1]=='R')
            {
                if(k%2)
                    cout<<k/2 + 1;
                else
                    cout<<k/2;
                nl;
                continue;
            }
        }
        vi arr;
        int lsum=0;
        int rsum=0;
        fori(0,n)
        {
            if(a[i] == 'L')
            {
                if(rsum!=0)
                {
                    arr.push_back(rsum);
                    rsum=0;
                }
                lsum--;
            }
            if(a[i]=='R')
            {
                if(lsum!=0)
                {
                    arr.push_back(lsum);
                    lsum=0;
                }
                rsum++;
            }
        }
        if(lsum!=0)
        {
            arr.push_back(lsum);
        }
        if(rsum!=0)
        {
            arr.push_back(rsum);
        }
        for(i=0,j=0;(i<arr.size() && j<k);i++,j++)
        {
            if(a[i]=='L')
            {
              x--;
            }
            else if(a[i]=='R')
            {
                x++;
            }
            if(x==0)
            {
                i=-1;
                count++;
            }
        }
        cout<<count;
        nl;
    }
    return 0;
}
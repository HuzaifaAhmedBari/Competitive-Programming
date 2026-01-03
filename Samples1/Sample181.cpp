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
        ll n,x,y;
        cin>>n>>x>>y;
        // while(y>=3 && x>=1 && n>=1)
        // {
        //     n--;
        //     x--;
        //     y-=3;
        // }
        // while(n>=1 && x>=2)
        // {
        //     n--;
        //     x-=2;
        // }
        ll no3 = y/3;
        ll no2 = x;
        if(no2/2>=n)
        {
            cout<<"YES";
            nl;
            continue;
        }
        ll mini = min(no2,no3);
        if(mini==no3)
        {
            n-=mini;
            no2-=mini;
        }
        else if(mini==no2)
        {
            n-=mini;
            no2-=mini;
        }
        if(no2==0)
        {
            if(n==0)
            {
                cout<<"YES";
                nl;
                continue;
            }
        }
        if(no2/2>=n)
        {
            cout<<"YES";
            nl;
            continue;
        }
        cout<<"NO";
        nl;
        // if(n==0)
        // {
        //     cout<<"YES";
        //     nl;
        // }
        // else
        // {
        //     cout<<"NO";
        //     nl;
        // }
    }
    return 0;
}
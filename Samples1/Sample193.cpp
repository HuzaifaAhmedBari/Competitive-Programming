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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    if(m>=n)
    {
        bool flag=true;
        while(m>0 || n>0)
        {
            if(flag)
            {
                cout<<'G';
                flag=!flag;
                m--;
            }
            else if(n>0)
            {
                cout<<'B';
                flag=!flag;
                n--;
            }
            else
            {
                flag=!flag;
            }
        }
    }
    else
    {
        bool flag=true;
        while(m>0 || n>0)
        {
            if(flag)
            {
                cout<<'B';
                flag=!flag;
                n--;
            }
            else if(m>0)
            {
                cout<<'G';
                flag=!flag;
                m--;
            }
            else
            {
                flag=!flag;
            }
        }
    }
    return 0;
}
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
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define yesno(expr) (expr)? cout<<"Yes" : cout<<"No"
#define Yesno(expr) (expr)? cout<<"YES" : cout<<"NO"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int n;
    cin>>n;
    vector<vector<char>> arr(n, vector<char>(n,'#'));
    fori(0,n)
    {
        forj(n+1-i,n)
        {
            if(i<=j)
            {
            fork(0,i+1)
            {
                for(int l=0;i<j+1;i++)
                {
                    if(i&1)
            {
                if(arr[k][l] == '#')
                {
                    arr[k][l] = '.';
                }
                else if(arr[i][j]=='#')
                {
                    arr[k][l] = '.';
                }
                else
                {
                    arr[k][l]='#';
                }
            }
            else
            {
                if(arr[k][l] == '#')
                {
                    arr[k][l] = '.';
                }
                else if(arr[k][l]=='.')
                {
                    arr[k][l] = '#';
                }
                else
                {
                    arr[k][l]='.';
                }
            }
        }
                }
            }
            
        }
    }
    fori(0,n)
    {
        forj(0,n)
        {
            cout<<arr[i][j];
        }
        nl;
    }
    return 0;
}
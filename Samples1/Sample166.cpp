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
        int a, b;
        cin>>a>>b;
        vii arr(a, vi(a, 0));
        arr[0][0] = b;
        fori(0,a)
        {
            forj(0,a)
            {
                if(j==1)
                {
                    arr[i][j] = arr[i-1][j-1];
                }
                if(j==i)
                {
                    arr[i][j] = arr[i-1][j];
                }
                if(1<j<i)
                {
                    arr[i][j] = arr[i-1][j-1] ^ arr[i-1][j];
                }
            }
            if(i==a-1)
            {
                forj(0,a)
                {
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
                break;
            }
        }
    }
    return 0;
}
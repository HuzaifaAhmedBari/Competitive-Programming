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
#define all(vec) vec.begin(), vec.end()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int n,q;
    cin>>n>>q;
    vl arr(n);
    input(arr);
    ll temp;
    ll mini = *min_element(all(arr));
    ll maxi = *max_element(all(arr));
    while(q--)
    {
        bool flag = true,flag2=false;
        cin>>temp;
        if(temp<mini)
        {
            if(n&1)
            {
                cout<<"NEGATIVE";
                nl;
            }
            else
            {
                cout<<"POSITIVE";
                nl;
            }
            continue;
        }
        else if(temp>maxi)
        {
            cout<<"POSITIVE";
            nl;
            continue;
        }
        fori(0,n)
        {
            if(temp==arr[i])
            {
                cout<<"0";
                nl;
                break;
            }
            if(temp<arr[i])
            {
                if((n-i)&1)
                {
                    cout<<"NEGATIVE";
                    nl;
                }
                else
                {
                    cout<<"POSITIVE";
                    nl;
                }
                break;
            }
        }
        // fori(0,n)
        // {
        //     if(temp-arr[i]<0)
        //     {
        //         flag=!flag;
        //     }
        //     else if(temp-arr[i]==0)
        //     {
        //         cout<<"0";
        //         flag2=true;
        //         nl;
        //         break;
        //     }
        // }
        // if(flag2)
        //     continue;
        // if(flag)
        // {
        //     cout<<"POSITIVE";
        // }
        // else
        // {
        //     cout<<"NEGATIVE";
        // }
    }
    return 0;
}
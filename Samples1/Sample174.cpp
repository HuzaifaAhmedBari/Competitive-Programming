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
        ll a;
        cin>>a;
        ll temp = sqrt(a);
        ll temp2 = a+a-1;
        ll temp3 = sqrt(temp2);
        if(a==1)
        {
            cout<<-1;
            nl;
        }
        else if(temp3*temp3 == temp2)
        {
            forr(a-2,1)
            {
                cout<<i<<" ";
            }
            cout<<a<<" "<<a-1;
            nl;
        }
        else if(temp*temp==a)
        {
            forr(a-1,1)
            {
                cout<<i<<" ";
            }
            cout<<a<<endl;
        }
        else
        {
            forr(a,1)
            {
                cout<<i<<" ";
            }
            nl;
        }
    }
    return 0;
}
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
    ll t;
    cin>>t;
    ll n;
    ll sum1=0;
    ll sum2=0;
    ll lex1=LLONG_MIN,lex2=LLONG_MIN;
    vl arr1, arr2;
    ll temp1=0,temp2=0;
    for(ll i=0;i<t;i++)
    {
        cin>>n;
        if(n>0)
        {
            sum1+=n;
            temp1++;
            lex2 = max(lex2,temp2);
            temp2=0;
            arr1.push_back(n);
        }
        else
        {
            sum2+=abs(n);
            temp2++;
            lex1=max(lex1,temp1);
            temp1=0;
            arr2.push_back(-n);
        }
    }
    lex1=max(lex1,temp1);
    lex2=max(lex2,temp2);
    if(sum1>sum2)
    {
        cout<<"first";
        nl;
    }
    else if(sum2>sum1)
    {
        cout<<"second";
        nl;
    }
    else
    {
        if(arr1>arr2)
        {
            cout<<"first";
            nl;
        }
        else if(arr2>arr1)
        {
            cout<<"second";
            nl;
        }
        else if(n>0)
        {
            cout<<"first";
            nl;
        }
        else
        {
            cout<<"second";
            nl;
        }
    }

    return 0;
}
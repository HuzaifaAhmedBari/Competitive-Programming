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
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int n;
    cin>>n;
    vl arr,fre(2000,1);
    ll sum=0;
    int temp;
    fori(0,n)
    {
        cin>>temp;
        if(fre[temp]==1)
        {
            arr.push_back(temp);
            fre[temp] = 0;
        }
    }
    sahi(arr);
    if(arr.size()>2)
    {
        fori(0,arr.size()-2)
        {
            if(arr[i]==arr[i+1]-1 && arr[i]==arr[i+2]-2)
            {
                cout<<"YES";
                nl;
                re;
            }
        }
    }
    cout<<"NO";
    nl;
    re;
    return 0;
}
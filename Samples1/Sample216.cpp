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
    int t = 1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi arr(n);
        vi arr1;
        string a;
        cin>>a;
        int temp = int(a[0])-'0';
        arr1.push_back(temp);
        fori(0,n)
        {
            if(i>0)
            {
                if(int(a[i])-'0'==1)
                {
                    arr1.push_back(1);
                }
                else if(arr1[arr1.size()-1]==0)
                {
                    continue;
                }
                else
                {
                    arr1.push_back(0);
                }
            }
        }
        ll sum= accumulate(arr1.begin(),arr1.end(),0);
        if(sum>arr1.size()-sum)
        {
            cout<<"Yes";
            nl;
        }
        else
        {
            cout<<"No";
            nl;
        }
    }
    return 0;
}
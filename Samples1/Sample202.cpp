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
#define forr(a,b) for(int j=a;j>=b;j--)
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
        vi arr(n),fre(200000,0);
        fori(0,n)
        {
            cin>>arr[i];
            fre[arr[i]]=1;
        }
        int ans = arr.size() - 2;
        int temp1,temp2;
        bool flag=false;
        if(fre[ans]==1 && fre[1]==1)
        {
            cout<<1<<" "<<ans<<endl;
            continue;
        }
        fori(2,ceil(sqrt(ans))+1)
        {
            if(fre[i]==1 && fre[ans/i]==1 && i*(ans/i)==ans)
            {
                cout<<i<<" "<<ans/i<<endl;
                break;
            }
        }
    }
    return 0;
}
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
#define forr(a,b) for(int l=a;l>=b;l--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
int main()
{
    io;
    int n,m;
    cin>>n>>m;
    vii arr(n);
    fori(0,n)
    {
        int temp;
        cin>>temp;
        arr[i].push_back(temp);
        cin>>temp;
        arr[i].push_back(temp);
        forj(0,temp)
        {
            int temp2;
            cin>>temp2;
            arr[i].push_back(temp2);
        }
    }
    fori(0,n)
    {
        forr(n-1,1)
        {
            for(int j=l-1;j>=0;j--)
            {
                ll count=0;
                if(arr[l][0]>=arr[j][0])
                {
                    if(arr[j].size()<arr[l].size())
                    {
                        continue;
                    }
                    for(int k=0;k<arr[j][1];k++)
                    {
                        if(arr[j][k]==arr[l][k])
                        {
                            count++;
                        }
                    }
                    if(count==arr[l][1])
                    {
                        cout<<"No";
                        nl;
                        re;
                    }
                }
            }
        }
    }
    cout<<"Yes";
    nl;
    return 0;
}
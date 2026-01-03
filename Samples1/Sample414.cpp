//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<"\n"
#define re return 0
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define us unordered_set<ll>
#define all(vec) vec.begin(), vec.end()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(ll i=a;i<b;i++)
#define forj(a,b) for(ll j=a;j<b;j++)
#define fork(a,b) for(ll k=a;k<b;k++)
#define forr(a,b) for(ll r=a;r>=b;r--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define print(vec) for(auto x : vec) cout<<x<<" "
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
        vl arr(n);
        input(arr);
        ll sum = arr[0];
        bool flag1=false,flag2=false;
        fori(0,n)
        {
            if(arr[i]&1)
                flag1=true;
            else
                flag2=true;
        }
        arr.erase(arr.begin());
        fori(0,arr.size())
        {
            if((sum+arr[i])&1)
            {
                sum+=arr[i];
                arr.erase(arr.begin()+i);
                i=-1;
            }
        }
        bool flag3=true;
        if((*max_element(all(arr))&1) == (sum&1))
        {
            if(((sum&1==1) && flag2==true) || ((sum&1==0) && flag1==true))
            {
                --sum;
                fori(0,arr.size())
                {
                    if((sum+arr[i])&1)
                    {
                        sum+=arr[i];
                        arr.erase(arr.begin()+i);
                        i=-1;
                    }
                    else
                    {
                        --sum;
                        --i;
                    }
                }
                cout<<sum;
                flag3=false;
            }
        }
        if(flag3)
        cout<<max(sum,*max_element(all(arr)));
        nl;
    }
    return 0;
}
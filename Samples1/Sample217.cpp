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
        vi arr(n),arr2;
        fori(0,n)
        {
            cin>>arr[i];
        }
        int k=0;
        sahi(arr);
        int j;
        while(arr2.size()>2)
        {
            if(k>0)
            {
                arr = arr2;
            }
            if(!(n&1))
            {
                n=(n/2)-1;
                j = arr.size()-2;
            }
            else
            {
                n=(n/2);
                j=arr.size()-2;
            }
            fori(0,n)
            {
                arr2.push_back((arr[i]+arr[j])/2);
                j--;
            }
            arr2.push_back(arr[arr.size()-1]);
            k++;
        }
        cout<<(arr2[0]+arr2[1])/2;
        nl;
    }
    return 0;
}
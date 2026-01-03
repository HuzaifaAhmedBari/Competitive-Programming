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
#define ulta(vec) sort(vec.begin(),vec.end(),greater<ll>())
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
        int a;
        ll b;
        cin>>a>>b;
        vector<char> arr1(a);
        vl array;
        vi fre(a);
        fori(0,a)
        {
            cin>>arr1[i];
        }
        fori(0,a)
        {
            cin>>fre[i];
        }
        ll sum=0;
        fori(0,a)
        {
            if(arr1[i]=='R')
            {
                sum+=fre[i];
            }
            else if(arr1[i]=='B')
            {
                if(sum!=0)
                {
                    array.push_back(sum);
                }
                sum=0;
            }
        }
        array.push_back(sum);
        ulta(array);
        fori(0,b)
        {
            array[i] = 0;
        }
        cout<<accumulate(array.begin(),array.end(), 0);
        nl;
    }
    return 0;
}
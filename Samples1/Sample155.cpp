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
    vii arr(t, vi(3));
    ll sum1=0,sum2=0,sum3=0;
    fori(0, t)
    {
        cin >> arr[i][0];
        cin >> arr[i][1];
        cin >> arr[i][2];
        sum1 += arr[i][0];
        sum2 += arr[i][1];
        sum3+= arr[i][2];
    }
    if(!sum1 && !sum2 && !sum3)
    {
        cout << "YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}
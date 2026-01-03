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
    int temp = n;
    if(temp<10)
    {
        cout<<"0"<<temp<<endl;
        re;
    }
    if(temp<16)
    {
        cout<<"0"<<char(temp-10+'A')<<endl;
        re;
    }
    // temp = n%10;
    // n/=10;
    // int temp2= n%10;
    // temp2 = 16 * temp2;
    temp = n%16;
    n/=16;
    int temp2=n%16;
    if(temp2<10)
    {
        cout<<temp2;
    }
    else
    {
        cout<<char(temp2-10+'A');
    }
    if(temp<10)
    {
        cout<<temp<<endl;
    }
    else
    {
        cout<<char(temp-10+'A')<<endl;
        re;
    }
    return 0;
}
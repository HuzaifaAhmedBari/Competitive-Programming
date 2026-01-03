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
    ll n;
    cin>>n;
    vector<pair<string,int>> pii;
    string a;
    int b;
    int flag;
    fori(0,n)
    {
        
        flag=1;
        cin>>a;
        cin>>b;
        forj(0,i)
        {
            if(pii[j].first == a)
            {
                if(b>0)
                {
                    b+=pii[j].second;
                    pii.erase(pii.begin() + j);
                }
                else
                {   
                    int temp = pii[j].second;
                    pii[j].second += b;
                    b+=temp;
                    pii.push_back({a,b});
                    flag=0;
                }
            }
        }
        if(flag)
            pii.push_back({a,b});
    }
    int maxi = INT_MIN;
    int found = -1;
    fori(0,pii.size())
    {
        if(maxi < pii[i].second)
        {
            maxi = pii[i].second;
            found = i;
        }
    }
    cout<<pii[found].first<<endl;
    return 0;
}
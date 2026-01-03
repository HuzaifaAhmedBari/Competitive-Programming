#include <iostream>
#include <map>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    while(n!=0)
    {
        map<string,long long> m;
        for(long long i=0;i<n;i++)
        {
            string s;
            cin>>s;
            m[s]++;
        }
        long long maxi = 0;
        string ans;
        for(auto &x:m)
        {
            if(x.second>maxi)
            {
                maxi = x.second;
                ans=x.first;
            }
        }
        cout<<ans<<endl;
        cin>>n;
    }
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,j;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int ans=0;
        int n,k;
        j=0;
        cin>>n>>k;
        while(j!=k)
        {
            ans++;
            if(ans%n != 0)
            {
                j++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
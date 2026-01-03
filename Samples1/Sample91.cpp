#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    if(n<=k)
    {
        cout<<n;
        return 0;
    }
    long long int ans = k;
    n -= k;
    for(int i=0;i<n;i++)
    {
        ans = ans*2;
    }
    cout<<ans;
    return 0;
}
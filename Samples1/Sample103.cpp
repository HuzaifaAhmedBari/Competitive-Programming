#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int index=0;
    int ans = INT_MIN;
    int temp;
    int sum=0;
    for(int i=1;i<=5;i++)
    {
        sum=0;
        for(int j=1;j<=4;j++)
        {
            cin>>temp;
            sum+=temp;
        }
        if(sum>ans)
        {
            ans = sum;
            index = i;
        }
    }
    cout<<index<<" "<<ans;
    return 0;
}
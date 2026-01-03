#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double a,b,c;
    cin>>a>>b>>c;
    double sum = a+b+c;
    double pa = sum - a;
    double pb = sum - b;
    double pc = sum - c;
    double ansa = ((pa/100)*a)*1000;
    double ansb = ((pb/100)*b)*1000;
    double ansc = ((pc/100)*c)*1000;
    int ans = min(ansa,ansb);
    if(ans<ansc)
    {
        cout<<int(ans);
    }
    else    cout<<int(ansc);
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    int a,b,c;
    cin>>t>>a>>b>>c;
    int sum=0;
    sum += t/a;
    sum += t/b;
    sum += t/c;
    sum -= t/(a*b);
    sum -= t/(a*c);
    sum -= t/(b*c);
    sum += t/(a*b*c);
    cout<<sum;
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int w1,h1,w2,h2;
    cin>>w1>>h1>>w2>>h2;
    int low1,side1;
    low1=w1+2;
    side1=h1;
    int high2,side2;
    high2=w2+2;
    side2=h2;
    int maxlength = (high2>low1)? high2 : low1;
    int ans = maxlength*2 + side1*2+side2*2;
    cout<<ans<<endl;
}
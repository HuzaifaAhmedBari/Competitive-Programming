#include<iostream>
using namespace std;
int main()
{
    int i,j,h1,m1,h2,m2,n;
    cin>>h1>>m1;
    cin>>h2>>m2;
    cin>>n;
    int t1=(h1*60) + m1;
    int t2=(h2*60) + m2;
    int dur = t2-t1;
    cout<<dur-n;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int count=0;
    cin>>n;
    int temp;
    if(n>=100)
    {
        temp = n/100;
        n-=temp*100;
        count+=temp;
    }
    if(n>=20)
    {
        temp = n/20;
        n-=temp*20;
        count+=temp;
    }
    if(n>=10)
    {
        temp = n/10;
        n-=temp*10;
        count+=temp;
    }
    if(n>=5)
    {
        temp = n/5;
        count+=temp;
        n-=temp*5;
    }
    if(n>=1)
    {
        temp = n/1;
        count+=temp;
        n-=temp;
    }
    cout<<count<<endl;
}
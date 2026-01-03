#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int i,j,t,a,b,temp=1,temp2=1;
    cin>>t;
    int ans[t] ={0};
    for(i=0;i<t;i++)
    {
        cin>>a>>b;
        if(b%2 == 0)
            --b;
        temp = (b+1) / 2;
        if(a%2 == 0)
            --a;
        temp2 = (a+1) / 2;
        ans[i] = temp * temp2;
    }
    for(i=0;i<t;i++)
    {
        cout<<ans[i]<<endl;
    }
}
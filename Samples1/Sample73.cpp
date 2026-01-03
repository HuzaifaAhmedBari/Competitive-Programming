#include<iostream>
using namespace std;
int main()
{
    int t,n,x,y,a;
    cin>>t;
    int ans[t] = {0};
    for(int i=0;i<t;i++)
    {
        cin>>n>>x>>y;
        if(y<(x*2))
        {
            ans[i] = n*x;
        }
        else
        {
            if(n%2==0)
            {
                ans[i] = (n/2)*y;
            }
            else
            {
                ans[i] = (n/2)*y;
                ans[i]+=x;
            }
        }
    }
    for(int i=0;i<t;i++)
        cout<<ans[i]<<endl;
}
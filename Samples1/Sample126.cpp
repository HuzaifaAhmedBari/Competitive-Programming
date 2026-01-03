#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%2==0)
    {
        int ans = n/2;
        if(ans%2==0)
            cout<<ans<<" "<<ans<<endl;
        else
            cout<<ans-1<<" "<<ans+1<<endl;
        return 0;
    }
    else
    {
        cout<<9<<" "<<n-9<<endl;
    }
}
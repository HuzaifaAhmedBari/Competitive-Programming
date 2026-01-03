#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int temp,i;
    if(n==1)
    {
        cout<<1<<endl<<1<<endl;
    }
    for(i=9;i>=1;i--)
    {
        temp = n/i;
        if(temp*i==n && n!=i)
        {
            cout<<temp<<endl;
            for(int j=1;j<=temp;j++)
            {
                cout<<i<<" ";
            }
            return 0;
        }
    }
}
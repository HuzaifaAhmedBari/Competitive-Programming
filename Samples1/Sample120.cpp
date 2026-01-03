#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int flag;
    char a[120];
    while(t--)
    {
        flag=1;
        cin >> a;
        int len = strlen(a);
        if(len==1)
        {
            cout<<1<<endl;
            continue;
        }
        for(int i=len;i>=1;i--)
        {
            if(a[i] == a[i-1])
            {
                cout<<1<<endl;
                flag=0;
                break;
            }
        }
        if (flag==1)
            cout<<len<<endl; 
            

    }
}
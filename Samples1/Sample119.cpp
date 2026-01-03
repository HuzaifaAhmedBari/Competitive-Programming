#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char a[12];
    while(n--)
    {
        cin>>a;
        int len = strlen(a);
        for(int i=0;i<len-2;i++)
        {
            cout<<char(a[i]);
        }
        cout<<"i"<<endl;
    }
}
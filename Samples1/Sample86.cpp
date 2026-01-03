#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,n,change=1;
    char temp;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        change=1;
        cin>>n;
        char a[n+1];
        cin>>a;
        for(int j=0;j<=n;j++)
        {
            if(a[j] == 'A')
            {
                temp = a[j];
                for(int k=j-1;k>=0;k--)
                {
                    a[k] = temp + change;
                    if(change==1)
                        change=0;
                    else
                        change=1;
                }
            }
            if(a[j] == 'B')
            {
                temp = a[j];
                for(int k=j-1;k>=0;k--)
                {
                    a[k] = temp - change;
                    if(change==1)
                        change=0;
                    else
                        change=1;
                }
            }
        }
        for(int j=0;j<=n;j++)
        {
            if(a[j] == 'A' || a[j] == 'B')
                cout<<char(a[j]);
            else if(j==n-1 && a[j-1] =='A')
            {
                cout<<"B";
                a[j] = 'B';
            }
            else if(j==n-1 && a[j-1] =='B')
            {
                cout<<"A";
                a[j] = 'A';
            }
            else if(a[j+1] == 'A')
            {
                cout<<'B';
                a[j] = 'B';
            }
            else if(a[j+1] == 'B')
            {
                cout<<"A";
                a[j] = 'A';
            }
            else if(a[j+2] == 'A' && j<n-2)
            {
                cout<<'A';
                a[j] = 'A';
            }
            else if(a[j+2] == 'B' && j<n-2)
            {
                cout<<"B";
                a[j] = 'B';
            }
            else if(a[j-1] == 'A')
            {
                cout<<"B";
                a[j] = 'B';
            }
            else if(a[j-1] == 'B')
            {
                cout<<"A";
                a[j] = 'A';
            }
            else
            {
                cout<<"B";
                a[j] = 'B';
            }
        }
        cout<<endl;
    }   
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a,b,t;
    cin>>t;
    int flag;
    for(int i=0;i<t;i++)
    {
        flag=0;
        cin>>a>>b;
        if(a>b)
        {
            int temp=b;
            b=a;
            a = temp;
        }
        for(int j=a; flag==0;j++)
        {
            if(j%a == 0 && j%b==0)
            {
                cout<<j<<endl;
                flag=1;
                break;
            }
        }

    }

    return 0;
}
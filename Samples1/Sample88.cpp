#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,n,count,flag;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        flag=0;
        cin>>n;
        count=0;
        int arr[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        for(int j=1;j<n;j++)
        {
            if(arr[j] == 1 && arr[j-1] > 1)
            {
                cout<<-1<<endl;
                flag=1;
                break;
            }
            for(; arr[j] < arr[j-1];count++)
            {
                arr[j] = pow(arr[j],2);
            }
        }
        if(flag==0)
            cout<<count<<endl;
    } 
    return 0;
}
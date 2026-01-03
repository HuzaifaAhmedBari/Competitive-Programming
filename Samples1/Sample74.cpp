#include<iostream>
using namespace std;
int main()
{
    int n,flag=1;
    double r = 1;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(flag==-1)
            continue;
        if(i==0)
            continue;
        else if(i==1)
            r = arr[i] / (double)arr[i-1];
        else if(r != (arr[i] / (double)arr[i-1]))
        {
            flag=-1;
        }
    }
    (flag == 1)? cout<<"Yes" : cout<<"No";
}
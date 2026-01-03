#include<iostream>
using namespace std;
int main()
{
    int t,x;
    cin>>t>>x;
    int arr[3] = {0};
    arr[t-1] = 1;
    arr[x-1] = 1;
    for(int i=0;i<3;i++)
    {
        if(arr[i] == 0)
            cout<<i+1;
    }
}
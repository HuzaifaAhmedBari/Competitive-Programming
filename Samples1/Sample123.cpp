#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i]>>arr2[i];
        if(i>=1)
        {
            if(arr2[i]<arr2[i-1])
            {
                cout<<"Happy Alex"<<endl;
                return 0;
            }
        }
    }
    cout<<"Poor Alex"<<endl;
}
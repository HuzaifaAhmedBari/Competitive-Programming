#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int fre[100000];
    int max=INT_MIN;
    int index = 0;
    int max2=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        fre[arr[i]]++;
        if(i==0)
        {
            max2=fre[arr[i]];
            index=0;
        }
        else
        {
            index = (fre[arr[i]]>max2)? arr[i] : index;
            max2 = (fre[arr[i]]>max2)? fre[arr[i]] : max2;
        }
        max = (arr[i]>max)? arr[i] : max;
    }
    int sum=0;
    for(int i=1;i<=max;i++)
    {
        if(i!=index)
        {
            sum+=fre[i];
        }
    }
    if(n/max2>=2 && n%2==0)
        cout<<n/2<<endl;
    else if(n/max2>=2 && n%2!=0)
        cout<<n/2+1<<endl;
    else
        cout<<(max2-sum)+sum<<endl;
}
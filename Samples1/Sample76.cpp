#include<iostream>
using namespace std;
int comp(const void *a, const void*b)
{
    return *(int *)b - *(int *)a;
}
int main()
{
    int i,j,t,flag1=-2,flag2=-2,flag3=-2,a=75,count=0;
    cin>>t;
    int arr[t];
    for(i=0;i<t;i++)
    {
        cin>>arr[i];
    }
    qsort(arr,t,sizeof(int),comp);
    flag1=arr[0];
    for(i=1;i<t;i++)
    {
        if(flag1 != arr[i] && flag1!=-1)
        {
            flag2=arr[i];
            flag1=-1;
        }
        else if(flag2 != arr[i] && flag2!=-1 && flag1==-1)
        {
            flag3=arr[i];
            count++;
            flag2=-1;
        }
        else if(flag3==arr[i] && flag2==-1)
        {
            count++;
        }
    }
    cout<<flag3<<" "<<count;
}
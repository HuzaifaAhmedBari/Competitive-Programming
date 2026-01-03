#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,d,i,j,flag = 0;
    cin>>n>>d;
    int arr[n][2];
    int ans[n] ={0};
    int done[n] = {0};
    ans[i] = 1;
    for(i=0;i<n;i++)
    {
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    for(i=0;i<n;i++)
    {
        flag = 0;
        if(done[i] == 1)
            continue;
        if(ans[i] == 1)
        {
            done[i] = 1;
            for(j=0;j<n;j++)
            {
                if(ans[j] == 1)
                    continue;
                else if(sqrt(pow(arr[i][0] - arr[j][0],2) + pow(arr[i][1] - arr[j][1],2)) <= d)
                {
                    ans[j] = 1;
                    flag = 1;
                }
            }
        }
        if(flag==1)
            i=0;
    }
    for(i=0;i<n;i++)
    {
        if(ans[i] == 1)
            cout<<"Yes"<<endl;
        else   
            cout<<"No"<<endl;
    }
}
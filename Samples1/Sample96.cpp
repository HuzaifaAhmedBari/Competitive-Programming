#include<iostream>
using namespace std;
int main()
{
    int t,temp,temp2,temp3,i,j;
    cin>>t;
    int ans1[t],ans2[t], ans3[t];
    int fre[t];
    for(i=0;i<t;i++)
    {
        int n;
        cin>>n;
        
            ans1[i] = 0;
            ans2[i] =0;
        for(j=0;j<n;j++)
        {
            cin>>temp;
            temp2 = temp/30 + 1;
            temp3 = temp/60 + 1;
            ans1[i] += temp2 * 10;
            ans2[i] += temp3 * 15;
        }
        if(ans1[i]<ans2[i])
        {
            ans3[i] = ans1[i];
            fre[i] = 1;
        }
        else if(ans2[i]<ans1[i])
        {
            ans3[i] = ans2[i];
            fre[i] = 2;
        }
        else if(ans1[i] == ans2[i])
        {
            ans3[i] = ans1[i];
            fre[i] = 3;
        }
        cout<<"Case "<<i+1<<": ";
        if(fre[i] == 1)
        {
            cout<<"Mile "<<ans3[i];
        }
        else if(fre[i] == 2)
        {
            cout<<"Juice "<<ans3[i];
        }
        else if(fre[i] == 3)
        {
            cout<<"MILE Juice "<<ans3[i];
        }
        cout<<endl;
    }
}
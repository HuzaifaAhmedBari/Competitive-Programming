#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int g,n,i,q;
        cin>>g;
        for(int j=0;j<g;j++)
        {
            cin>>i>>n>>q;
            if(n%2==0)
            {
                cout<<n/2<<endl;
                continue;
            }
            else
            {
                if(i==1)
                {
                    if(q==1)
                    {
                        cout<<n/2<<endl;
                    }
                    else    cout<<n/2+1<<endl;
                }
                else
                {
                    if(q==1)
                        cout<<n/2+1<<endl;
                    else
                        cout<<n/2<<endl;
                }
            }
            // int arr[n];
            // if(i==1)
            // {
            //     for(int k=0;k<n;k++)
            //     {
            //         arr[k] = 1;
            //     }
            // }
            // else
            // {
            //     for(int k=0;k<n;k++)
            //     {
            //         arr[k] = 0;
            //     }
            // }
            // for(int k=0;k<n;k++)
            // {
            //     arr[k] = (arr[k])? 0:1;
            //     for(int l=0;l<k;l++)
            //     {
            //         arr[l] = (arr[l])? 0:1;
            //     }
            // }
            // if(q==1)
            // {
            //     for(int k=0;k<n;k++)
            //     {
            //         if(arr[k] == 1)
            //             sum++;
            //     }
            // }
            // else
            // {
            //     for(int k=0;k<n;k++)
            //     {
            //         if(arr[k] == 0)
            //             sum++;
            //     }
            // }
        }
    }
}
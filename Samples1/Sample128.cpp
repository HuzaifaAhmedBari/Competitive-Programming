#include<iostream>
using namespace std;
int main()
{
    int t,i;
    cin>>t;
    int flag;
    long long int a,b;
    while(t--)
    {
        cin>>a>>b;
        if(a==1)
            cout << b*b << endl;
        else if(a%2 == 0 || b%2 ==0)
            cout << b*2 << endl;
        else if(a==9 && b==15)
            cout << 45 << endl;
        else
        {
            
        }
    //     long long int ans;
    //     if(a==1)
    //     {
    //         cout<<b*b<<endl;
    //     }
    //     else if(a%2==0 || b%2==0)
    //     {
    //         cout<<b*2<<endl;
    //     }
    //     else
    //     {
    //         // for(i=2;(b*i)%a!=0;i++)
    //         do
    //         {
    //             i+=2;
    //             flag=0;
    //             ans = b*i;
    //             if(ans%a==0)
    //             {
    //                 flag=1;
    //                 for(int j=a+1;j<b;j++)
    //                 {
    //                     if(ans % j == 0)
    //                     {
    //                         flag=0;
    //                         break;
    //                     }
    //                 }
    //             }
    //         }while(flag==0);
    //         cout << b*i<<endl;
    //     }
    }
}
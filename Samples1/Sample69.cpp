#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int n1,n2,temp1,temp2;
    cin>>n1;
    cin>>n2;
    if(n1<n2)
    {
        while(n1!=0)
        {
            temp1=n1%10;
            temp2=n2%10;
            if(temp1+temp2>=10)
            {
                cout<<"Hard";
                return 0;
            }
            n1/=10;
            n2/=10;
        }
        cout<<"Easy";
    }
    else
    {
        while(n2!=0)
        {
            temp1=n1%10;
            temp2=n2%10;
            if(temp1+temp2>=10)
            {
                cout<<"Hard";
                return 0;
            }
            n1/=10;
            n2/=10;
        }
        cout<<"Easy";
    }
}
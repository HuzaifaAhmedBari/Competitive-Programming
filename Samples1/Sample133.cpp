#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int n,x,i;
    cin>>n>>x;
    x = 2<<x-1;
    n--;
    int digit = 1;
    while(n--)
        digit*=10;
    int count=0;
    for(i=digit*10-1;i>=digit;i--)
    {
        if(i%x==0)
        {
            break;
        }
    }
    long long int end = i;
    for(i=digit;i<digit*10;i++)
    {
        if(i%x==0)
        {
            count++;
            break;
        }
    }
    count += (end - i)/x;
    cout<<count<<endl;

}
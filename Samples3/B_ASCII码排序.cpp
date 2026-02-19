#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        sort(s.begin(),s.end());
        for(int i=0;i<3;i++)
        {
            cout<<s[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
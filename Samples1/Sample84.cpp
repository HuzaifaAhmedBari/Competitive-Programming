#include <cmath>
#include <cstdio>
#include <vector>
#include <limits.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,a,b,d=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        d=0;
        cin>>a>>b;
        char arr[a+1];
        cin>>arr;
        int fre[26] = {0};
        for(int j=0;j<a;j++)
        {
            fre[arr[j] - 'a']++;
            if(fre[arr[j] - 'a'] == 1)
                d++;
        }
        if(d<b)
        {
            cout<<"NO";
            continue;
        }
        cout<<"YES"<<endl;
        cout<<d-b<<endl;
        for(int j=0;j<b;j++)
        {
            int max=-1;
            int index;
            for(int k=0;k<26;k++)
            {
                   if(fre[k] > max)
                   {
                        max = fre[k];
                        index=k;
                   }
            }
            fre[index] = 0;
            for(int k=0;k<max;k++)
            {
                cout<<char('a'+index);
            }
        }
        cout<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    vector<int> a;
    int temp;
    int n=0;
    int count=1;
    int max=INT_MIN;
    while(n<10)
    {
        cin>>temp;
        a.push_back(temp);
        n++;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++)
    {
        if(a[i] == a[i+1])
        {
            continue;
        }
        if(a[i]+1 == a[i+1])
        {
            count++;
        }
        if(a[i]+1 != a[i+1])
        {
            max = (count>max)? count : max;
        }
        if(i==n-2 && max==INT_MIN)
        {
            max = count;
        }
    }
    cout<<max<<endl;
}    
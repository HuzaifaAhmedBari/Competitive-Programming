#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char temp;
    cin>>n;
    int flag=1;
    int d=n*2+4;
    vector<vector<bool>> adj(d, vector<bool>(d,false));
    int y=n/2+1,x=n/+1;
    adj[x][y] = true;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        if(temp=='R')
        {
            x++;
            if(adj[x][y])
            {
                flag=0;
            }
            adj[x][y] = true;
        }
        else if(temp=='L')
        {
            x--;
            if(adj[x][y])
            {
                flag=0;
            }
            adj[x][y] = true;;
        }
        else if(temp=='U')
        {
            y++;
            if(adj[x][y])
            {
                flag=0;
            }
            adj[x][y] = true;;
        }
        else if(temp=='D')
        {
            y--;
            if(adj[x][y])
            {
                flag=0;
            }
            adj[x][y] = true;;
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i+1;j<=n;j++)
    //     {
    //         if(pii[i].first == pii[j].first && pii[i].second == pii[j].second)
    //         {
    //             cout<<"Yes"<<endl;
    //             return 0;
    //         }
    //     }
    // }
    // cout<<"No"<<endl;
    (flag)? cout<<"No"<<endl : cout<<"Yes"<<endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//---------------- YOUR SOLUTION ----------------//

vector<ll> solve(vector<ll> b) {
    // Paste your code here.
    // Return {} if you output -1.

    int n = b.size();

    vector<pair<ll,ll>> a(n);
    for(int i=0;i<n;i++)
        a[i]={b[i],i};

    sort(a.begin(),a.end());

    ll cur=a[0].first,sum=0,mx=0;
    vector<ll> ans(n,-1);
    bool flag=true;

    for(int i=0;i<n;i++){
        ll cnt=0,l=i;
        while(i<n && a[i].first==cur){
            i++;
            cnt++;
        }
        if(i==n) break;

        ll z=a[i].first-sum;

        if(z>0 && z%cnt==0 && z/cnt>mx){
            for(int j=l;j<i;j++)
                ans[a[j].second]=z/cnt;
            mx=z/cnt;
        }else{
            flag=false;
            break;
        }

        sum+=(z/cnt)*cnt;
        cur=a[i].first;
        i--;
    }

    if(!flag || sum!=a.back().first)
        return {};

    for(int i=0;i<n;i++)
        if(ans[i]==-1)
            ans[i]=mx+1;

    return ans;
}

//-----------------------------------------------//

vector<ll> shadow(vector<ll> a){
    int n=a.size();
    vector<ll> b(n);
    for(int i=0;i<n;i++){
        ll s=0;
        for(int j=0;j<n;j++)
            if(a[j]<a[i]) s+=a[j];
        b[i]=s;
    }
    return b;
}

int main(){

    srand(time(0));

    while(true){

        int n=1+rand()%6;

        vector<ll> original(n);

        for(int i=0;i<n;i++)
            original[i]=1+rand()%4;

        vector<ll> b=shadow(original);

        // brute lexicographically smallest
        vector<ll> best;
        bool found=false;

        vector<ll> cur(n);

        function<void(int)> dfs=[&](int idx){

            if(idx==n){

                if(shadow(cur)==b){

                    if(!found || cur<best){
                        found=true;
                        best=cur;
                    }
                    return;
                }

                return;
            }

            for(int x=1;x<=4;x++){
                cur[idx]=x;
                dfs(idx+1);
            }
        };

        dfs(0);

        vector<ll> mine=solve(b);

        if((!found && !mine.empty()) ||
           (found && mine.empty()) ||
           (found && mine!=best)){

            cout<<"Mismatch!"<<endl;

            cout<<"Shadow : ";
            for(auto x:b) cout<<x<<" ";
            cout<<endl;

            cout<<"Expected : ";
            if(!found) cout<<-1;
            else for(auto x:best) cout<<x<<" ";
            cout<<endl;

            cout<<"Mine : ";
            if(mine.empty()) cout<<-1;
            else for(auto x:mine) cout<<x<<" ";
            cout<<endl;

            return 0;
        }
    }
}
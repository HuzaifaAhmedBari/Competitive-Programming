//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//find_by_order(k): returns iterator to k-th smallest element (0-based)
//order_of_key(x): returns number of elements strictly less than x
#define ld long double
#define nl cout<<"\n"
#define re return 0
#define fs first
#define sc second
#define MOD 1000000007
#define pii pair<int,int>
#define vl vector<int>
#define vll vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vvpii vector<vector<pair<int,int>>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define vc vector<char>
#define vcc vector<vector<char>>
#define vs vector<string>
#define vss vector<vector<string>>
#define all(vec) vec.begin(), vec.end()
#define allr(vec) vec.rbegin(), vec.rend()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int r=a;r>=b;r--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)

template <typename A, typename B>
istream& operator>>(istream &in, pair<A,B> &p) {
    in >> p.first >> p.second;
    return in;
}
template <typename T>
istream& operator>>(istream &in, vector<T> &v) {
    for (auto &x : v) in >> x;
    return in;
}

template <typename A, typename B>
ostream& operator<<(ostream &out, const pair<A,B> &p) {
    out << p.first << " " << p.second;
    return out;
}
template <typename T>
ostream& operator<<(ostream &out, const vector<T> &v) {
    for (auto &x : v) out << x;
    return out;
}

int main()
{
    io;
    int n,m;
    cin>>n>>m;
    vs s(n);
    cin>>s;
    int w;
    cin>>w;
    vector<pair<char,int>> mv(w);
    cin>>mv;
    queue<pair<pii,char>> q;
    fori(0,n)
        forj(0,m)
            if(s[i][j]>='A' and s[i][j]<='Z')
                q.push({{i,j},s[i][j]});
    int i = 0;
    inline function<bool(int,int)> safe = [&](int x, int y) {
        return x>=0 and y>=0 and x<n and y<m and s[x][y]!='#';
    };
    while(not q.empty() and i<w)
    {
        int t = q.size();
        forj(0,t)
        {
            auto [d,c] = q.front();
            q.pop();
            auto [x,y] = d;
            if(mv[i].fs=='N')
            {
                if(safe(x-1,y))
                    q.push({{x-1,y},c});
            }
            else if(mv[i].fs=='S')
            {
                if(safe(x+1,y))
                    q.push({{x+1,y},c});
            }
            else if(mv[i].fs=='E')
            {
                if(safe(x,y+1))
                    q.push({{x,y+1},c});
            }
            else if(mv[i].fs=='W')
            {
                if(safe(x,y-1))
                    q.push({{x,y-1},c});
            }
        }
        mv[i].sc--;
        if(mv[i].sc==0)
            i++;
    }
    if(q.empty())
        cout<<"no solution";
    else
    {
        vc ans;
        while(not q.empty())
        {
            ans.push_back(q.front().sc);
            q.pop();
        }
        sahi(ans);
        cout<<ans;
    }
    nl;
    return 0;
}
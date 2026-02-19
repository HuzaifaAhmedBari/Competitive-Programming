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
#define ll long long int
#define ld long double
#define nl cout<<"\n"
#define re return 0
#define fs first
#define sc second
#define MOD 1000000007
#define pii pair<ll,ll>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vpii vector<pair<ll,ll>>
#define vvpii vector<vector<pair<ll,ll>>>
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
#define fori(a,b) for(ll i=a;i<b;i++)
#define forj(a,b) for(ll j=a;j<b;j++)
#define fork(a,b) for(ll k=a;k<b;k++)
#define forr(a,b) for(ll r=a;r>=b;r--)
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
istream& operator>>(istream &in, vector<pair<A,B>> &vp) {
    for (auto &p : vp) in >> p.first >> p.second;
    return in;
}

template <typename A, typename B>
ostream& operator<<(ostream &out, const pair<A,B> &p) {
    out << p.first << " " << p.second;
    return out;
}
template <typename T>
ostream& operator<<(ostream &out, const vector<T> &v) {
    for (auto &x : v) out << x << " ";
    return out;
}
template <typename A, typename B>
ostream& operator<<(ostream &out, const vector<pair<A,B>> &vp) {
    for (auto &p : vp) out << p.first << " " << p.second << "\n";
    return out;
}

int main()
{
    io;
    ll n,m,p;
    cin>>n>>m>>p;
    vl speed(p);
    cin>>speed;
    vcc s(n,vc(m));
    fori(0,n)
        cin>>s[i];
    map<char,vpii> place;
    vl ans(p,0);
    fori(0,n)
    {
        forj(0,m)
        {
            if(s[i][j]=='.' or s[i][j]=='#')
                continue;
            place[s[i][j]].push_back({i,j});
            ans[s[i][j]-'1']++;
        }
    }
    function<bool(ll,ll,char,ll)>safe = [&](ll x,ll y, char c,ll moves) {
        return x>=0 and x<n and y>=0 and y<m and s[x][y]=='.' and moves>0;
    };
    queue<pair<pii,pii>> q; //x,y position , character,movements left
    for(auto [x,y]:place['1'])
        q.push({{x,y},{0LL,speed[0]}});
    place['1'].clear();
    ll flag = 0, next = 0;
    vpii d = {{-1,0},{1,0},{0,-1},{0,1}};
    while(flag!=p+1)
    {
        flag++;
        while(not q.empty())
        {
            auto [b,c] = q.front();
            auto [x,y] = b;
            auto [cur,sp] = c;
            q.pop();
            // cout<<x<<" "<<y<<" "<<cur<<" "<<sp;
            // nl;
            flag = 0;
            for(auto [cx,cy] : d)
            {
                ll dx = x, dy = y;
                dx+=cx;dy+=cy;
                if(not safe(dx,dy,char(cur+'1'),sp))
                    continue;
                s[dx][dy] = char(cur+'1');
                    ans[cur]++;
                if(sp==1)
                    place['1'+cur].push_back({dx,dy});
                else
                    q.push({{dx,dy},{cur,sp-1}});
            }
        }
        next++;
        if(next==p)
            next = 0;
        for(auto [x,y]:place[next+'1'])
            q.push({{x,y},{next,speed[next]}});
        place[next+'1'].clear();
    }
    cout<<ans;
    nl;
    return 0;
}
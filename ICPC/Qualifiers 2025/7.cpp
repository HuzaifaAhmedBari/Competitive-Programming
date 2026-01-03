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
#define us unordered_set<ll>
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

vb is_prime;
void sieve(ll n) {
    is_prime.assign(n+1,true);
    is_prime[0] = is_prime[1] = false;
    for(ll i=2;i*i<=n;i++) {
        if(is_prime[i]) {
            for(ll j=i*i;j<=n;j+=i)
                is_prime[j] = false;
        }
    }
}
bool isprime(ll n) {
    if(n<2)	return false;
    if(n==2 || n==3)	return true;
    if(n%2==0 || n%3==0)	return false;
    for(ll i=5;i*i<=n;i++)
    {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}
ll nextprime(ll n)	{ return (isprime(n))? n : nextprime(n+1); }
ll sum_digits(ll n)	{ return (n<10)? n : n%10 + sum_digits(n/10); }
ll gcd(ll a, ll b)	{ return (b==0)? a : gcd(b,a%b); }
ll lcm(ll a, ll b)	{ return (a*b)/gcd(a,b); }
int main()
{
    io;
    ll t = 1;
    // cin>>t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (ll i = 0; i < n; i++) cin >> grid[i];

        ll sx=-1, sy=-1, tx=-1, ty=-1, lx=-1, ly=-1;
        vector<pair<ll,ll>> mirrors;
        vector<char> mirror_type;

        for (ll i=0;i<n;i++)
        {
            for (ll j=0;j<m;j++)
            {
                char c = grid[i][j];
                if(c=='S')
                {
                    sx=i; sy=j;
                }
                else if(c=='T')
                {
                    tx=i; ty=j;
                }
                else if(c=='L')
                {
                    lx=i; ly=j;
                }
                else if(c=='/' || c=='\\')
                {
                    mirrors.push_back({i,j}); mirror_type.push_back(c);
                }
            }
        }

        ll k = mirrors.size();
        ll dx[4] = {-1,0,1,0};
        ll dy[4] = {0,1,0,-1};
        ll reflSlash[4] = {1,0,3,2};
        ll reflBack[4]  = {3,2,1,0};

        vector<bitset<2500>> tera(k), seedha_waly(k);

        for (ll idx=0; idx<k; idx++)
        {
            for (int state=0; state<2; state++)
            { 
                bitset<2500> used;
                queue<array<int,3>> q;
                int x = mirrors[idx].first, y = mirrors[idx].second;
                used[x*m+y] = 1;
                for (int d=0; d<4; d++) q.push({x,y,d});
                while(!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    int cx=cur[0], cy=cur[1], dir=cur[2];
                    int nx=cx+dx[dir], ny=cy+dy[dir];
                    if(nx<0 || nx>=n || ny<0 || ny>=m)
                        continue;
                    if(grid[nx][ny]=='#') continue;
                    int nd = dir;
                    char c = grid[nx][ny];
                    if(nx==mirrors[idx].first && ny==mirrors[idx].second){
                        if(state==0) c = mirror_type[idx];
                        else c = (mirror_type[idx]=='/') ? '\\' : '/';
                    }
                    if(c=='/') nd = reflSlash[dir];
                    else if(c=='\\') nd = reflBack[dir];
                    if(!used[nx*m+ny]){
                        used[nx*m+ny]=1;
                        q.push({nx,ny,nd});
                    }
                }
                if(state==0) tera[idx]=used;
                else seedha_waly[idx]=used;
            }
        }

        ll ans=0, mn=LLONG_MAX;
        for (ll mask=0; mask<(1LL<<k); mask++)
        {
            bitset<2500> used_total;
            ll cost=0;
            for (ll i=0;i<k;i++)
            {
                if(mask & (1LL<<i))
                {
                    used_total |= seedha_waly[i];
                    cost++;
                } else {
                    used_total |= tera[i];
                }
            }
            if(used_total[sx*m+sy] || used_total[tx*m+ty] || grid[sx][sy]=='#' || grid[tx][ty]=='#')
                continue;

            queue<pair<int,int>> rq;
            vector<vb> vis(n, vb(m,0));
            vis[sx][sy]=1;
            rq.push({sx,sy});
            bool reachable=false;
            while(!rq.empty())
            {
                auto p = rq.front(); rq.pop();
                int x=p.first, y=p.second;
                if(x==tx && y==ty)
                {
                    reachable=true;
                    break;
                }
                for(int d=0; d<4; d++)
                {
                    int nx=x+dx[d], ny=y+dy[d];
                    if(nx<0||nx>=n||ny<0||ny>=m)
                        continue;
                    if(vis[nx][ny] || grid[nx][ny]=='#' || used_total[nx*m+ny])
                        continue;
                    vis[nx][ny]=1;
                    rq.push({nx,ny});
                }
            }
            if(reachable)
            {
                ans++;
                mn = min(mn,cost);
            }
        }

        if(ans==0)
            cout<<0<<" "<<-1;
        else
            cout<<ans<<" "<<mn;
        nl;
    }
    return 0;
}

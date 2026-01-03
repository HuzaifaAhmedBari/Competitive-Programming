//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
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
#define vpii vector<pair<ld,ld>>
#define vvpii vector<vector<pair<ll,ll>>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define us unordered_set<ll>
#define all(vec) vec.begin(), vec.end()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(ll i=a;i<b;i++)
#define forj(a,b) for(ll j=a;j<b;j++)
#define fork(a,b) for(ll k=a;k<b;k++)
#define forr(a,b) for(ll r=a;r>=b;r--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fork(0,vec.size()) cin>>vec[k]
#define print(vec) for(auto x : vec) cout<<x<<" "
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
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

const int ALPHABET = 26; // lowercase a-z
vector<vector<int>> trie(1, vector<int>(ALPHABET, -1));
vector<ll> cnt(1, 0); // count of words passing through each node
vector<bool> end(1,false);

void insert(const string &s) {
    int node = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[node][c] == -1) {
            trie[node][c] = trie.size();
            trie.push_back(vector<int>(ALPHABET, -1));
            cnt.push_back(0);
            end.push_back(false);
        }
        node = trie[node][c];
        cnt[node]++;
    }
    end[node] = true;
}

bool starts_with(const string &prefix) {
    int node = 0;
    for (char ch : prefix) {
        int c = ch - 'a';
        if (trie[node][c] == -1)
            return false;
        node = trie[node][c];
    }
    return true;
}


int main()
{
    io;
    ll n,m;
    while(cin>>n)
    {
        cin>>m;
        ld s,v;
        cin>>s>>v;
        vpii strt(n),dest(m);
        fori(0,n)
            cin>>strt[i].fs>>strt[i].sc;
        fori(0,m)
            cin>>dest[i].fs>>dest[i].sc;
        function<ld(ld,ld,ld,ld)>d = [&](ld x,ld y,ld a,ld b){
            return ((ld)sqrt(((x-a)*(x-a))+((y-b)*(y-b))));
        };
        sort(all(strt),[&](pair<ld,ld>x, pair<ld,ld>y){
            return d(x.fs,x.sc,0,0)<d(y.fs,y.sc,0,0);
        });
        sort(all(dest),[&](pair<ld,ld>x, pair<ld,ld>y){
            return d(x.fs,x.sc,0,0)<d(y.fs,y.sc,0,0);
        });
        ll j=0;
        ll count=0;
        vll adj(n+1);
        vl ans(m+1,-1);
        vb used1(n,false);
        fori(0,n)
        {
            forj(0,m)
            {
                if((d(strt[i].fs,strt[i].sc,dest[j].fs,dest[j].sc))/v<=s)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vb visited(m+1,false);
        function<bool(ll)>dfs = [&](ll u) {
            for(ll v:adj[u])
            {
                if(visited[v])  
                    continue;
                visited[v] = true;
                if(ans[v]==-1 or dfs(ans[v]))
                {
                    ans[v] = u;
                    return true;
                }
            }
            return false;
        };
        fori(0,n)
        {
            visited.assign(m+1,false);
            if(dfs(i))
                count++;
        }
        cout<<n-count<<endl;
    }
    return 0;
}
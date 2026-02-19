#include<bits/stdc++.h>
using namespace std;

#define ll long long 
using vll = std::vector<ll>;


bool isPrime(ll n){
    if(n == 2) return true;
    if(n < 2) return false;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

vll factorization(ll n){
    vll factors;
    while(n%2 == 0){
        factors.push_back(2);
        n/= 2;
    }
    for(ll i = 3; i*i <= n; i++){
        while(n%i == 0){
            factors.push_back(i);
            n = n/i;
        }
    }
    if(n > 1) factors.push_back(n);
    return factors;
}

vll sieve(ll n){
    vll sieveArr(n+1, 0);
    sieveArr[2] = 0;
    sieveArr[3] = 0;

    for(ll x = 2; x*x <= n; x++){
        if(sieveArr[x]) continue;
        for(ll i = x*2; i <= n; i+=x){
            if(sieveArr[i] == 0){
                sieveArr[i] = x;
            }
        }
    }
    return sieveArr;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b))*b;
}

unordered_set<ll> uiqueFactors(ll n){
    unordered_set<ll> factors;
    bool insert2 = false;
    while(n%2 == 0){
        if(!insert2){
            factors.insert(2);
            insert2 = true;
        }
        n/= 2;
    }
    for(ll i = 3; i*i <= n; i++){
        bool inserted = false;
        while(n%i == 0){
            if(!inserted){
                factors.insert(i);
                inserted = true;
            }
            n = n/i;
        }
    }
    if(n > 1) factors.insert(n);
    return factors;
}

ll phi(ll n){
    unordered_set<ll> f = uiqueFactors(n);
    ll ans = n;
    for(auto a: f){
        ans *= (a - 1);
        ans /= a;
    }
    return ans;
}


vll segmentedSieve(ll L, ll R) {
    // Generate all primes up to sqrt(R)
    ll limit = sqrt(R);
    vector<bool> mark(limit + 1, false);
    vll primes;
    
    for (ll i = 2; i <= limit; ++i) {
        if (!mark[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= limit; j += i) {
                mark[j] = true;
            }
        }
    }
    
    
    vector<bool> isPrimeSegment(R - L + 1, true);
    
    for (ll p : primes) {
        
        ll start = max(p * p, ((L + p - 1) / p) * p);
        
        for (ll j = start; j <= R; j += p) {
            isPrimeSegment[j - L] = false;
        }
    }
    
    
    if (L == 1) {
        isPrimeSegment[0] = false;
    }
    
    
    vll result;
    for (ll i = 0; i < isPrimeSegment.size(); i++) {
        if (isPrimeSegment[i]) {
            result.push_back(L + i);
        }
    }
    
    return result;
}


vector<bool> segmentedSieveBool(ll L, ll R) {
    ll limit = sqrt(R);
    vector<bool> mark(limit + 1, false);
    vll primes;
    
    for (ll i = 2; i <= limit; ++i) {
        if (!mark[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= limit; j += i) {
                mark[j] = true;
            }
        }
    }
    
    vector<bool> isPrimeSegment(R - L + 1, true);
    
    for (ll p : primes) {
        ll start = max(p * p, ((L + p - 1) / p) * p);
        
        for (ll j = start; j <= R; j += p) {
            isPrimeSegment[j - L] = false;
        }
    }
    
    if (L == 1) {
        isPrimeSegment[0] = false;
    }
    
    return isPrimeSegment;
}



void input_graph_unWt(vector<vll>& adj, ll& n, ll &m, bool dir){
    for(ll i = 0; i < m; i++){
        ll u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        if(dir){
            adj[v].push_back(u);
        }
    }
}

pair<bool, vll> bipartite(vector<vll> &adj){
    ll n = adj.size() - 1;
    vll color(n+1, -1);
    vll vis(n+1, -1);

    queue<ll> q;
    for(ll i = 1; i <= n; i++){
        if(color[i] == -1){
            q.push(i);
            color[i] = 1;

            while(!q.empty()){
                ll cur_node = q.front();
                q.pop();
                for(auto a: adj[cur_node]){
                    if(color[a] == -1){
                        color[a] = 1 - color[cur_node];
                        q.push(a);
                    }else if(color[a] == color[cur_node]){
                        return {false, {}};
                    }
                }
            }
        }
    }
    return {true, color};
}

void solve(){
    ll n,h;
    cin >> n>> h;
    vll arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll x = 0;
    ll y = *max_element(arr.begin(),arr.end());
    ll z;

    while(x < y){
        z=(x+y)/2;
        ll cur=h;
        bool status = true;
        for(auto i:arr){
            if(i>z){
                if(cur<=i){ 
                    status = false;
                    break;
                    }
                cur-=i;
                }
            }
            if(status){
                y = z;
            }else{
                x = z + 1;
            }
    }
    cout << x << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    

    return 0;
}
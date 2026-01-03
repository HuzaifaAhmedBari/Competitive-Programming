#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<ll, ll>
#define vpii vector<pair<ll, ll>>
#define vvpii vector<vector<pair<ll, ll>>>

const ll INF = 1e18;

struct Edge {
    ll to, time, risk;
};

struct State {
    ll node, max_risk, total_time;
    
    bool operator>(const State& other) const {
        if (max_risk != other.max_risk) 
            return max_risk > other.max_risk;
        return total_time > other.total_time;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    
    while(t--){
        ll n, m;
        cin >> n >> m;
        
        vector<vector<Edge>> adj(n + 1);
        
        for (ll i = 0; i < m; i++) {
            ll u, v, w, r;
            cin >> u >> v >> w >> r;
            adj[u].push_back({v, w, r});
            adj[v].push_back({u, w, r});
        }
        
        vector<ll> best_risk(n + 1, INF);
        vector<ll> best_time(n + 1, INF);
        
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({1, 0, 0});
        best_risk[1] = 0;
        best_time[1] = 0;
        
        while (!pq.empty()) {
            auto [node, current_risk, current_time] = pq.top();
            pq.pop();
            
            
            if (current_risk > best_risk[node] || 
                (current_risk == best_risk[node] && current_time > best_time[node])) {
                continue;
            }
            
            for (auto& edge : adj[node]) {
                ll new_risk = max(current_risk, edge.risk);
                ll new_time = current_time + edge.time;
                
                
                if (new_risk < best_risk[edge.to] || 
                   (new_risk == best_risk[edge.to] && new_time < best_time[edge.to])) {
                    best_risk[edge.to] = new_risk;
                    best_time[edge.to] = new_time;
                    pq.push({edge.to, new_risk, new_time});
                }
            }
        }
        
        if (best_risk[n] == INF) {
            cout << -1 << "\n";
        } else {
            cout << best_risk[n] << " " << best_time[n] << "\n";
        }
    }
    
    return 0;
}

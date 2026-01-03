#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> G[MAXN];
int degreeArr[MAXN];
int parent[MAXN][20];
int depthArr[MAXN];
int n;

// DFS to compute depth and 2^k parents for LCA
void dfs(int u, int p) {
    parent[u][0] = p;
    for (int i = 1; i < 20; i++)
        parent[u][i] = parent[parent[u][i - 1]][i - 1];

    for (int v : G[u]) {
        if (v == p) continue;
        depthArr[v] = depthArr[u] + 1;
        dfs(v, u);
    }
}

// LCA function
int lca(int u, int v) {
    if (depthArr[u] < depthArr[v]) swap(u, v);

    int diff = depthArr[u] - depthArr[v];
    for (int i = 19; i >= 0; i--)
        if (diff >> i & 1) u = parent[u][i];

    if (u == v) return u;

    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

// Dummy check function (replace with your real logic)
bool check(int r, const vector<tuple<int,int,int>> &lcas) {
    // Example placeholder: always true (you must define real condition)
    return true;
}

// Dummy answer output
void answer(int r) {
    cout << "Answer: " << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        degreeArr[u]++;
        degreeArr[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // Run DFS from node 1 to prepare LCA info
    dfs(1, 1);

    // Find all leaves
    vector<int> leaves;
    for (int i = 1; i <= n; i++) {
        if (degreeArr[i] == 1)
            leaves.push_back(i);
    }

    // Build LCA triples
    vector<tuple<int,int,int>> lcas;
    for (int i = 0; i + 1 < (int)leaves.size(); i += 2) {
        int a = leaves[i], b = leaves[i + 1];
        lcas.push_back({a, b, lca(a, b)});
    }

    if (leaves.size() % 2 == 1) {
        int a = leaves[0], b = leaves.back();
        lcas.push_back({a, b, lca(a, b)});
    }

    // Check candidates
    vector<int> candidates;
    for (int r = 1; r <= n; r++) {
        if (check(r, lcas)) {
            candidates.push_back(r);
        }
    }

    assert(candidates.size() == 1);
    answer(candidates[0]);
    return 0;
}

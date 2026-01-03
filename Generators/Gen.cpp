#include <bits/stdc++.h>
using namespace std;

struct PRNG {
    uint64_t state;
    PRNG(uint64_t seed) : state(seed) {}
    uint32_t next() {
        state ^= state << 10;
        state ^= state >> 7;
        state ^= state << 15;
        return (uint32_t)(state & 0xFFFFFFFF);
    }
    int nextInt(int l, int r) {
        return l + (next() % (r - l + 1));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input5.txt","w",stdout);

    int n = 50;          // max arrays
    int m = 250000;      // max indices
    int maxLen = 5000;   // max length of each array

    PRNG rng(123456789ULL);  // fixed seed for determinism

    cout << n << " " << m << "\n";

    // Generate n arrays
    for (int i = 0; i < n; i++) {
        int len = maxLen; // fixed max length for stress
        cout << len << " ";
        for (int j = 0; j < len; j++) {
            int val = rng.nextInt(-1000, 1000);
            cout << val << " ";
        }
        cout << "\n";
    }

    // Generate m indices uniformly distributed in [1, n]
    for (int i = 0; i < m; i++) {
        int idx = rng.nextInt(1, n);
        cout << idx << " ";
    }
    cout << "\n";

    return 0;
}
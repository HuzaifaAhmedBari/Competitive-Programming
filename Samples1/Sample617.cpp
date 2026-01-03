#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool beats(int i, int j, int n) {
    if (i == 1 && j == n) return true;
    if (i == n && j == 1) return false;
    return i > j;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> A, B;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') A.push_back(i + 1);
            else B.push_back(i + 1);
        }

        bool aliceWins = false;
        for (int ai : A) {
            bool safe = true;
            for (int bi : B) {
                if (beats(bi, ai, n)) {
                    safe = false;
                    break;
                }
            }
            if (safe) {
                aliceWins = true;
                break;
            }
        }

        cout << (aliceWins ? "Alice\n" : "Bob\n");
    }
    return 0;
}

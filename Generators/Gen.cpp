#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cout<<t<<"\n";

    int n = 200000;
    int m = 200000;
    long long h = 1000000000;

    cout<<n<<" "<<m<<" "<<h<<"\n";

    for(int i = 0; i<n; i++)
    {
        cout<<0;
        if(i+1<n) cout<< " ";
    }
    cout << "\n";

    for(int i = 0; i<m; i++)
    {
        cout<<1<<" "<<1<<"\n";
    }

    return 0;
}

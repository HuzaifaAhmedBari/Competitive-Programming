//Maqsad Nahi Bhoolna
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define nl cout<<endl
#define re return 0
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define all(vec) vec.begin(), vec.end()
#define sahi(vec) sort(vec.begin(),vec.end())
#define ulta(vec) sort(vec.begin(),vec.end(),greater<typename decltype(vec)::value_type>())
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forr(a,b) for(int i=a;i>=b;i--)
#define yes(expr) (expr)? cout<<"yes" : cout<<"no"
#define Yes(expr) (expr)? cout<<"Yes" : cout<<"No"
#define YES(expr) (expr)? cout<<"YES" : cout<<"NO"
#define input(vec) fori(0,vec.size()) cin>>vec[i]
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr)
void forest(int n, int m)
{
    vector<vector<int>> grid(n, vector<int>(m, 0));
    int odd = 1;

    if(m>=n)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (odd <= n * m) {
                    grid[i][j] = odd;
                    odd += 2;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (odd <= n * m) {
                    grid[j][i] = odd;
                    odd += 2;
                }
            }
        }
    }
    
    vector<int> evens;
    if(n>m)
    {
        for (int i = 2; i <= n * m; i += 2) {
            evens.push_back(i);
        }
    }
    else if(m>n)
    {
        for (int i = n*m; i >=2; i -= 2) {
            evens.push_back(i);
        }
    }
    else
    {
        for (int i = n*m-1; i >= 2; i -= 2) {
            evens.push_back(i);
        }
    }
    
    int cenR = n / 2, cenC = m / 2, index = evens.size() - 1;
    for (int l = 0; l <= max(cenR, cenC); l++) {
        for (int i = cenR - l; i <= cenR + l && i < n && i >= 0; i++) {
            for (int j = cenC - l; j <= cenC + l && j < m && j >= 0; j++) {
                if (grid[i][j] == 0 && index >= 0) {
                    grid[i][j] = evens[index--];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    io;
    int n, m;
    cin >> n >> m;
    if(n == 1 && m == 1) {
        cout << 1 << endl;
        return 0;
    }
    if((n == 1 && m <= 4) || (n <=4 && m == 1)) {
        cout << -1 << endl;
        return 0;
    }

    forest(n, m);
    return 0;
}
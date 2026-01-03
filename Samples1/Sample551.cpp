//Maqsad Nahi Bhoolna
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>

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

int main()
{
    io;
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    fori(0, n) {
        forj(0, n) {
            cin >> arr[i][j];
        }
    }

    int area = 0;
    int pm = 0;

    fori(0, n) {
        forj(0, n) {
            if (arr[i][j] <= 50) {
                area++;
                bool bdry = false;
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                    bdry = true;
                } 
                else {
                    if (arr[i - 1][j] > 50 || arr[i + 1][j] > 50 || arr[i][j - 1] > 50 || arr[i][j + 1] > 50) {
                        bdry = true;
                    }
                }
                if (bdry) {
                    pm++;
                }
            }
        }
    }

    cout << area << " " << pm << endl;
    re;
}
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
int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if(k==1)
        {
            set<ll> s;
            fori(0,n)
            {
                ll a;
                cin>>a;
                s.insert(a);
            }
            ll i=0;
            for(auto x:s)
            {
                if(i!=x)
                {
                    break;
                }
                else
                {
                    i++;
                }
            }
            cout<<i;
            nl;
        }
        else
        {
            vl arr(n);
            input(arr);
            ll low = 0, high = n, best = 0;
            while (low <= high)
            {
                ll mid = (low + high) / 2;
                if ([&](vl& a, ll x, ll k)
                {
                        if(x == 0)
                        {
                            return true;
                        }
                        set<ll> req;
                        fori(0,x){
                            req.insert(i);
                        }
                        set<ll> cur;
                        ll count = 0;
                        for (int num : a) {
                            if (num < x) {
                                cur.insert(num);
                            }
                            if (cur == req) {
                                count++;
                                cur.clear();
                                if (count >= k) {
                                    return true;
                                }
                            }
                        }
                        return count >= k;
                    }(arr, mid, k))
                {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            cout << best;
            nl;
        }
        }
    re;
}
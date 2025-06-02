// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<long long> 
#define vi vector<int>
#define F first
#define S second
#define inv(a) for (auto &it : a) cin >> it;
#define outv(a) for (auto &it : a) cout << it << " "; cout << "\n";
#define outv1(a) for (auto &it : a) cout << it << endl;
#define pb push_back
#define all(v) v.begin(), v.end()
#define pp pop_back()
#define rall(v) v.rbegin(), v.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int gcd(int a, int b) {return __gcd(a,b);}
// #define int long long 

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
// int my_rand(int a, int b) {
//     if (a > b) return 0;
//     return a + rng() % (b - a + 1);
// }

const int N = 2e5+2;
int n,m;
vl v(N);
vector<pair<ll,ll>> tr[N];



ll check(ll sum) {

    vl dp(n+1,-1e12);
    dp[1]=min(sum, v[1]);
    // dp[i]->max battery can have at vertex i
    
    for (int i = 1; i <= n; i++) 
    {
    
        for(auto &[u,w]: tr[i]) {
            if(dp[i]>=w) {
                dp[u]=max(dp[u], min(sum, dp[i]+v[u]));
            }
        }
    }
    return dp[n]>=0;
    
}

void solve(int t) { 
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
        tr[i].clear();
    }
    
    for (int i = 1; i <= m; i++) {
        int u,vv,w;
        cin>>u>>vv>>w;
        tr[u].pb({vv,w});
    }
    int lo = 1,hi=1e9;
    int ans = -1;
    while (lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(check(mid)) {
            hi = mid - 1;
            ans = mid;
        }
        else lo = mid + 1;
    }
    cout<<ans<<endl;
}
int32_t main() {
    fastio;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    

    int t=1;
    cin>>t;
    for (int i = 1; i<=t; i++)
    {
        solve(i);
    }
   
    
    
    return 0;
}
// https://codeforces.com/contest/2110/problem/D
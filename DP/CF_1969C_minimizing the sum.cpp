#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ll long long 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll inf = 1e18;

void solve() {
    int n,K;
    cin>>n>>K;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<vector<ll>> dp(n+3, vector<ll>(K+3, inf));
    dp[0][0]=0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            ll mn = inf;
            for (int p = 0; i+p<n && j+p<=K; p++) {
                mn = min(mn, v[i+p]);
                dp[i+p+1][j+p] = min(dp[i+p+1][j+p], dp[i][j]+mn*(p+1));
            }
        }
    }
    ll ans = inf;
    for (int i = 0; i <= K; i++) ans = min(ans, dp[n][i]);
    cout<<ans<<endl;
    
}

int32_t main() {
    fastio;
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve();
    }

    return 0;
}

// بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
// template <typename T> 
// using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define vi vector<int>
#define vl vector<long long>
#define vecp vector<pair<int, int>> 
#define ll long long
#define ull unsigned long long
#define F first
#define S second
#define pii pair<int, int>
#define inv(a) for(auto &it : a) cin >> it;
#define outv(a) for(auto &it : a) cout << it << " "; cout << "\n"
#define outv1(a) for(auto &it : a) cout << it << endl
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define inf 1e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//#define int long long

const int N= 3e5+1;
vector<int> tr[N],sz(N, 0);
int dp[N];

void dfs(int node, int par) {
    for(auto &it: tr[node]) {
        if(it==par) continue;
        dfs(it, node);
        sz[node]+=sz[it]+1;
    }
}



int maro_dp(int node,int parent) {
    // knapsack on binary tree
    // take size of left subtr,traverse right
    // take size of right subtr,traverse left

    int &ans = dp[node];
    if(ans!=-1) return ans;
    ans = 0;

    vl v;
    for(auto &it: tr[node]) {
        if(it==parent) continue;
        v.pb(it);
    }
    if(v.empty()) {
        return ans=0;
    }
    else if(v.size()==2){
        ans = max(ans, maro_dp(v[0], node)+sz[v[1]]);
        ans = max(ans, maro_dp(v[1], node)+sz[v[0]]);
    }
    else {
        ans = max(ans, sz[v[0]]);
    }
    return ans;
}

void solve(int tc) {
    int n;
    cin>>n;
    vi vis(n+2, 0);
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        tr[u].pb(v);
        tr[v].pb(u);
    }
    
    dfs(1,-1);
    memset(dp, -1, sizeof dp);

    cout<<maro_dp(1,-1)<<endl;
    
    for (int i = 0; i <= n; i++)
    {
        sz[i]=0;
        tr[i].clear();
        dp[i]=-1;
    }
    
    
}
 
int32_t main() { 
     
    fastio;
    int Tc=1;
    cin>>Tc;
    for (int T = 1; T <= Tc; T++)
    {
        solve(T);
    }
    
    
    return 0;
}
// https://codeforces.com/contest/1689/problem/C
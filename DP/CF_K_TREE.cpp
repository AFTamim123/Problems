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
#define int long long

const int N = 300;
int n,k,d;
int dp[300][2];
const int mod = 1e9+7;

int maro_dp(int sum, int ache) {
    // cout<<sum<<endl;
    if(sum==n && ache) return 1;
    if(sum>n) return 0;

    int &ans = dp[sum][ache];
    if(ans!=-1) return ans;
    ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans+=maro_dp(sum+i, (i>=d)||ache)%mod;
    }
    return ans%mod;
}
void solve(int tc) {
    cin>>n>>k>>d;
    memset(dp, -1, sizeof dp);
    cout<<maro_dp(0,0)%mod<<endl;
}
 
int32_t main() { 
     
    fastio;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
 
    int Tc=1;
    // cin>>Tc;
    for (int T = 1; T <= Tc; T++)
    {
        solve(T);
    }
    
    
    return 0;
}

// https://codeforces.com/problemset/problem/431/C
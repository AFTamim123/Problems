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
#define rall(v) v.rbegin(), v.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }



const int N = 5e3+2;
int dp[N][N],a[N],b[N],c[N],n;

void solve(int TC) {
    memset(dp, 0, sizeof dp);
    cin>>n;
    a[0]=0;
    b[0]=0;
    c[0]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) {
        c[i]+=a[i]*b[i]+c[i-1];
        dp[i][i]=c[i];
    }
   
    // dp[l][r] -> maximum sum of a[i]*b[i] if we reverse 
    // l to r...expension from all possible middle point
    // if we reverse l->r ans = dp[l][r]+preffix(1,l-1)+suffix(r+1,n)
    
    for (int i = 1; i <= n; i++)
    {
        int lo = i,hi=i;
        while (lo>=1 && hi<=n)
        {
            dp[lo][hi]=a[lo]*b[hi]+a[hi]*b[lo]*(lo!=hi)+dp[lo+1][hi-1];
            lo--,hi++;
        }
        lo = i,hi=i+1;
        while (lo>=1 && hi<=n)
        {
            
            dp[lo][hi]=a[lo]*b[hi]+a[hi]*b[lo]+dp[lo+1][hi-1];
            lo--,hi++;
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            ans = max(ans, dp[i][j]+c[i-1]+c[n]-c[j]);
        }
        
    }
    cout<<ans<<endl;
}

int32_t main() {
    fastio;
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    int Tc = 1;
    // cin >> Tc;
    for (int T = 1; T <= Tc; T++) {
        solve(T);
    }

    return 0;
}

// https://codeforces.com/contest/1519/problem/D

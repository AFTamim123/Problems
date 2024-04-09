#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define vi vector<int>
#define vl vector<long long>
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define inv(a) for(auto &it : a) cin >> it;
#define outv(a) for(auto &it : a) cout << it << " ";cout<<"\n"
#define outv1(a) for(auto &it : a) cout << it << " "<<"\n";cout<<"\n"
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define lcm(a,b) (a*b)/__gcd(a,b)
#define int long long

int n,k;
const int N=1e5+3;
vi tr[N];
vl a(N);
int ans = 0;
void dfs(int child, int parent, int maxC,int numC) {
    if(a[child]) numC++;
    else numC=0;
    maxC=max(maxC, numC);
    int numchild=0;
    for(int u: tr[child]) {
        if(u!=parent) dfs(u,child,maxC,numC),numchild++;
    }
    if(numchild==0 && maxC<=k) ans++;
}

void solve() {
    
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        tr[u].pb(v);
        tr[v].pb(u);
    }
    dfs(1,-1,0,0);
    cout<<ans<<endl;

    
}

int32_t main() {
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T=1;
    // cin>>T;
    while (T--) {
        solve();
    }

    return 0;
}

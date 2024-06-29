// بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define vi vector<int>
#define vl vector<long long>
#define vecp vector<pair<int, int>>
#define ll long long
#define F first
#define S second
#define pii pair<int, int>
#define inv(a) for (auto &it : a) cin >> it;
#define outv(a) for (auto &it : a) cout << it << " "; cout << "\n"
#define outv1(a) for (auto &it : a) cout << it << " " << "\n"; cout << "\n"
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"
const int mod = 1000000007;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll inf = 1e18;

const int N = 2e5+2;
vi t[N];
vector<long double> p(N),dis(N, 0);
vl vis(N, 0);

long double ans = 0.0;

void dfs(int v, long double d) {
    vis[v]=1;
    dis[v]=d;
    long double c = t[v].size();
    if(v!=1) c--;
    
    for(auto &it: t[v]) {
        if(!vis[it]) {
            p[it]=p[v]/(long double)c;
            dfs(it, dis[v]+1.0);
        }
    }
}
void solve() {
    int n;
    cin>>n;
    for (int i = 1; i <= n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        t[u].pb(v);
        t[v].pb(u);
    }
    p[1]=1;
    dfs(1,0);
    for (int i = 1; i <= n; i++)
    {
        if(t[i].size()==1)
            ans += p[i]*dis[i];
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

// expected value
// EV(x) = x*(p(x))
// probality of each node is p[parent]/number of child

int main() {
    fastio;
    int TC=1;
    // cin >> TC;
    while (TC--) {
        solve();
    }

    return 0;
}
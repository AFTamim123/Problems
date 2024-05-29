// بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define vi vector<int>
#define vl vector<long long>
#define vecp vector<pair<int,int>> 
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define inv(a) for(auto &it : a) cin >> it;
#define outv(a) for(auto &it : a) cout << it << " "; cout << "\n"
#define outv1(a) for(auto &it : a) cout << it << " " << "\n"; cout << "\n"
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define inf 1e9
const int mod = 1000000007;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
int lcm(int a, int b) { return (a * b) / __gcd(a, b); }


struct DSU {
  vector<int> par, rnk, sz;
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
    for (int i = 0; i <= n; ++i) par[i] = i;
  }
  int find(int i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() {  //number of con. comp
    return c;    
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    else --c;
    if (rnk[i] > rnk[j]) swap(i, j);
    par[i] = j;
    sz[j] += sz[i];
    if (rnk[i] == rnk[j]) rnk[j]++;
    return j;
  }
};


void solve(int TC) {
    cout<<"Case "<<TC<<":"<<endl;

    int n,m;
    cin>>n>>m;
    vector<pair<int, pair<int,int>>> edges;
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edges.pb({w, {u,v}});
    }
    int des; cin>>des;

    sort(all(edges));
    DSU ds(n+1);
    vector<pair<int,int>> tr[n+3];
    for (int i = 0; i < edges.size(); i++)
    {
        int w = edges[i].F;
        int u = edges[i].S.F;
        int v = edges[i].S.S;
        if(ds.find(u)==ds.find(v)) continue;
        ds.merge(u,v);
        tr[u].pb({v, w});
        tr[v].pb({u, w});
    }
    for (int i = 0; i < n; i++) {
        if(i==des) {
            cout<<0<<endl;
            continue;
        }
        if(ds.find(i)!=ds.find(des)) {
            cout<<"Impossible"<<endl;
            continue;
        }
        stack<pair<int, int>> st;
        st.push({i, -1});
        vl vis(n + 1, 0);
        int ans = -1;

        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            int now = node.F, mw = node.S;

            vis[now] = 1;
            if (now == des) {
                ans = mw;
                break;
            }
            for (auto &it : tr[now]) {
                int u = it.F;
                int w = it.S;
                if (!vis[u]) {
                    st.push({u, max(mw, w)});
                }
            }
        }
        cout<<ans<<endl;
    }
    
    
}

int32_t main() {
    fastio;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int tc = 1; 
    cin >> tc;
    for (int TC = 1; TC <= tc; TC++) {
        solve(TC);
    }

    return 0;
}

// https://lightoj.com/problem/country-roads

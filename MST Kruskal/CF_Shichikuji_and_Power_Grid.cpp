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
    int n; cin>>n;
    vector<pair<int,int>> city(n+1);
    for (int i = 1; i <= n; i++) cin>>city[i].F>>city[i].S;
    vl c(n+1),k(n+1);
    for (int i = 1; i <= n; i++) cin>>c[i];
    for (int i = 1; i <= n; i++) cin>>k[i];

    vector<pair<int, pair<int,int>>> edge;
    for (int i = 1; i <= n; i++) edge.pb({c[i], {0,i}});
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            int dis = abs(city[i].F-city[j].F)+abs(city[i].S-city[j].S);
            int cost = dis*(k[i]+k[j]);
            edge.pb({cost, {i,j}});
        }
    }
    sort(all(edge));
    DSU ds(n+2);
    vector<int> power_stat;
    vector<pair<int,int>> wires;
    int cost = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        int u = edge[i].S.F;
        int v = edge[i].S.S;
        int w = edge[i].F;
        if(ds.same(u,v)) continue;
        ds.merge(u,v);
        if(u==0 || v==0) power_stat.pb(max(u,v));
        else {
            wires.pb({u,v});
        }
        cost += w;
    }
    cout<<cost<<endl;
    cout<<power_stat.size()<<endl;
    outv(power_stat);
    cout<<wires.size()<<endl;
    for(auto it: wires) cout<<it.F<<" "<<it.S<<endl;
}

int32_t main() {
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tc = 1; 
    // cin >> tc;
    for (int TC = 1; TC <= tc; TC++) {
        solve(TC);
    }

    return 0;
}
// https://codeforces.com/contest/1245/problem/D
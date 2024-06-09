// بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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
#define inf 1e18
#define int long long
const int mod = 1000000007;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

template <typename T> 
using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vl v(n);
    inv(v);
    priority_queue<int, vi, greater<int>> pq;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        pq.push(v[i]);
        while (sum < 0) {
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << pq.size() << endl;

    return 0;
}
// https://codeforces.com/contest/1526/problem/C2
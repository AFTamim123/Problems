// بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define inf 1e9
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

const int N = 2e5+2;
int v[N],dp[N],n;


int marodp(int idx) {
    if(idx>n-1) return 0;
    int &ans  = dp[idx];
    if(ans!=LONG_LONG_MAX) return ans;

    int now = v[idx];
    ans = min(ans, marodp(idx+2)+now);
    ans = min(ans, marodp(idx+3)+now);

    if(idx+1<n) now += v[idx+1];

    ans = min(ans, marodp(idx+3)+now);
    ans = min(ans, marodp(idx+4)+now);

    return ans;
}

void solve(int TC) {
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        dp[i]=LONG_LONG_MAX;
    }
    
    cout<<marodp(0)<<endl;
    
    
}

int32_t main() {
    fastio;
    
   
    int tc = 1; 
    cin >> tc;
    for (int TC = 1; TC <= tc; TC++) {
        solve(TC);
    }

    return 0;
}

// https://codeforces.com/contest/1418/problem/C
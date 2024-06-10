// بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define outv(a) for (auto &it : a) cout << it << " "; cout << '\n'

bool cmp(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    if (a.first == b.first) {
        return a.second > b.second; 
    }
    return a.first < b.first; 
}
ll bin_expo(ll a, ll b, ll mod) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result % mod;
}

void solve() {
    int n; cin>>n;
    vector<ll> v(n);
    for(auto &it: v) cin>>it;
    ll mod = 998244353;
    vector<ll> pr(n, 0);
    pr[0]=v[0];
    for (int i = 1; i < n; i++) pr[i]+=pr[i-1]+v[i];
    ll mn = *min_element(pr.begin(), pr.end());
    if(mn>=0) {
        cout<<bin_expo(2,n,mod)<<endl;
        return;
    }
    ll cnt = 0,ans=0;
    for (int i = 0; i < n; i++)
    {
        if(pr[i]>=0) cnt++;
        else if(pr[i]==mn) {
            ans += bin_expo(2,cnt+(n-i-1), mod);
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TC; cin>>TC;
    while (TC--)
    {
        solve();
    }
    
    

    return 0;
}

// HINT: apply operation 2 when prefix sum is most min
// https://codeforces.com/contest/1984/problem/C2
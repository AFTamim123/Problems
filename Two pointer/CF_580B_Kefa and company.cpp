#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve() {
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>> v(n+1);
    v[0].F=0,v[0].S=0;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        v[i+1].F=a;
        v[i+1].S=b;
    }
    sort(all(v));
    for (int i = 1; i <= n; i++)
    {
        v[i].S+=v[i-1].S;
    }
    int ans = 0;
    int lo=1,hi=1;
    while (lo<=n && hi<=n)
    {
        if(hi<lo) swap(hi,lo);
        if(v[hi].F-v[lo].F<d) {
            ans = max(ans, v[hi].S-v[lo-1].S);
            hi++;
        }
        else {
            lo++;
        }
    }

    cout<<ans<<endl;
    
}


int32_t main() {
    fastio;

    int T=1;
    // cin>>T;
    while (T--) {
        solve();
    }

    return 0;
}
// https://codeforces.com/contest/580/problem/B
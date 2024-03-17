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
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define lcm(a,b) (a*b)/__gcd(a,b)
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

void koro(int lo, int hi, vl &v, vl &ans,int gobir) {
    if(lo>hi) return;
    int ind = -1,m=-1;
    for (int i = lo; i <= hi; i++)
    {
        if(v[i]>m) {
            m=v[i];
            ind=i;
        }
    }
    ans[ind]=gobir;
    koro(lo,ind-1,v,ans,gobir+1);
    koro(ind+1,hi,v,ans,gobir+1);
}
void solve() {
    int n;
    cin>>n;
    vl v(n);
    inv(v);
    vl ans(n, 0);
    koro(0,n-1,v,ans,0);
    outv(ans);

}

int32_t main() {
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int T=1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
https://codeforces.com/contest/1490/problem/D
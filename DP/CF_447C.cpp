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
    ll n;
    cin>>n;
    vl v(n);
    inv(v);
    vl pref(n, 0),suff(n,0);
    pref[0]=1;
    for (int i = 1; i < n; i++)
    {
        if(v[i]>v[i-1]) {
            pref[i]=pref[i-1]+1;
            
        }
        else {
            pref[i]=1;
        }
    }
    suff[n-1]=1;
    for (int i = n-2; i >= 0; i--)
    {
        if(v[i]<v[i+1]) {
            suff[i]=suff[i+1]+1;
        }
        else {
            suff[i]=1;
        }
    }
    int res = 1;
    for (int i = 0; i < n-1; i++) res=max(res, pref[i]+1);
    for (int i = 1; i < n; i++) res=max(res, suff[i]+1);

    for (int i = 1; i < n-1; i++)
    {
        if(v[i-1]+1<v[i+1]) {
            res=max(res, pref[i-1]+1+suff[i+1]);
        }
    }
    cout<<res<<endl;
    
}

int32_t main() {
    fastio;
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    
    
    int T=1;
    // cin>>T;
    while (T--) {
        solve();
    }

    return 0;
}

// https://codeforces.com/contest/447/problem/C
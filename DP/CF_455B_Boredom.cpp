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
#define inf LLONG_MAX
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long 

const int N = 1e5+5;
int dp[N][2];
vl v;
int n;
map<int,int> mp;

int koro(int idx, int nisi) {
    if(idx>=n) return 0;


    int &ans = dp[idx][nisi];
    if(ans!=0) {
        return ans;
    }
    if(!nisi) {
        ans = max({
            koro(idx+1, 1)+v[idx]*mp[v[idx]],
            koro(idx+1, 0)
        });
    }
    // nisi
    else {
        if(idx-1 >=0 && v[idx-1]+1!=v[idx]) {
            ans = max({
                koro(idx+1, 1)+v[idx]*mp[v[idx]],
                koro(idx+1, 0)
            });
        }
        else {
            ans = koro(idx+1, 0);
        }
    }
    return ans;
}

void solve() {
    cin>>n;
    
    for (int i = 0; i < n; i++)
    {
        int x; cin>>x;
        mp[x]++;
    }
    for(auto &it: mp) v.pb(it.F);
    sort(all(v));
    n=v.size();
    memset(dp, 0, sizeof dp);
    
    
    cout<<koro(0,0)<<endl;
    
}

int32_t main() {
    fastio;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    int TC=1;
    // cin>>TC;
    while(TC--) 
        solve();
 
    
    

    return 0;
}

// https://codeforces.com/contest/455/problem/A
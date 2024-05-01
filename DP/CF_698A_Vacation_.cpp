// https://codeforces.com/contest/698/problem/A
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
#define inf 1e9
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long


const int N = 105;
int dp[N+2][6],v[N],n;

int maro_dp(int idx, int agenisi) {

    int &ans = dp[idx][agenisi];
    if(ans!=-1) return ans;

    if(idx>=n) return 0;
    

    
    ans = maro_dp(idx+1, 0)+1;
    
    if(v[idx]==1) {
        if(agenisi!=1) {
            ans = min({
                ans, maro_dp(idx+1, 1),
            });
        }
    }
    if(v[idx]==2) {
        if(agenisi!=2) {
            ans = min({
                ans,maro_dp(idx+1, 2)
            });
        }
    }
    else if(v[idx]==3){

        if(agenisi==0) {
            ans = min({
                ans,
                maro_dp(idx+1, 1),
                maro_dp(idx+1, 2),
            });
        }
        else if(agenisi==1) {
            ans = min({
                ans,
                maro_dp(idx+1, 2),
            });
        }
        else {
            ans = min({
                ans,
                maro_dp(idx+1, 1),
            });
        }
    }
    return ans;
}

void solve() {
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<maro_dp(0,0)<<endl;
}



int32_t main() {
    fastio;
   
    
   int t=1;
//    cin>>t;
   while (t--)
   {
        solve();
   }
   
    
    
    
    return 0;
}
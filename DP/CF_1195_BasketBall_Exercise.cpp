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
int n;
int arr[2][N];
int dp[3][N];

int koro(int age_nisi, int idx) {

    if(idx>n-1) return 0;
    if(dp[age_nisi][idx]!=0) {
        return dp[age_nisi][idx];
    }
    
    if(age_nisi==0) {
       return dp[age_nisi][idx] = max({
            koro(1, idx+1)+arr[0][idx],
            koro(2, idx+1)+arr[1][idx],
            koro(0, idx+1),
       });
    }
    else if(age_nisi==1) {
        return dp[age_nisi][idx] = max({
            koro(2, idx+1)+arr[1][idx],
            koro(0, idx+1),
       });
    }
    else {
       return dp[age_nisi][idx] = max({
            koro(1, idx+1)+arr[0][idx],
            koro(0, idx+1),
       });
    }
}

void solve() {
    cin>>n;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }
    memset(dp, 0, sizeof dp);

    cout<<koro(0,0)<<endl;
    
    
    
    
}

int32_t main() {
    fastio;
    
    solve();
    
    return 0;
}
// https://codeforces.com/contest/1195/problem/C
// https://atcoder.jp/contests/abc208/tasks/abc208_a

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
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define inf 1e9
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

const int N = 1003;
int dp[103][N][2];
bool parbe = false;
int n, sum;

int laga_dp(int ache, int sum, int nisi) {
    if (ache == 0 || sum == 0) return 0;
    if (ache < 0 || sum < 0) {
        return INT_MIN;
    }

    int &ans = dp[ache][sum][nisi];
    if (ans != -1) return ans;
   
    for (int i = 1; i <= 6; i++) {
        
        ans = max(ans, laga_dp(ache - 1, sum - i, 1) + i);
         ans = max(ans, laga_dp(ache, sum, 0));
    }
    return ans;
}

int main() {
  
    fastio;

    cin >> n >> sum;
    memset(dp, -1, sizeof dp);

    int koto = laga_dp(n, sum, 0);

    if(sum<n) no;
    else if (koto >= sum) yes;
    else no;

    return 0;
}

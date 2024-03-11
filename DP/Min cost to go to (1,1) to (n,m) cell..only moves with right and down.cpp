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
#define int long long
#define lcm(a,b) (a*b)/__gcd(a,b)
using namespace std;
using namespace __gnu_pbds;

const int N = 300;
int n,m;
int grid[N][N];
int dp[N][N];
int solve(int i, int j) {

    if(i==n || j==m) return LONG_LONG_MAX;

    if(i==n-1 && j==m-1) return grid[n-1][m-1];
    
    if(dp[i][j]!=-1) return dp[i][j];

    return dp[i][j]=grid[i][j] + min(solve(i,j+1),
                     solve(i+1, j));
}


int32_t main() {
    fastio;
    cin>>n>>m;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j]=-1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<solve(0,0)<<endl;
    return 0;
}

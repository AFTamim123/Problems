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
// #define int long long 

const int N = 1e4+3;
vi v;
void sieve() {
    vi vis(N, 0);
    for (int i = 2; i*i < N; i++)
    {
        if(vis[i]) continue;

        for(int j=i*i; j<N; j+=i) 
            vis[j]=1;
    }
    for (int i = 2; i < N; i++)
    {
        if(!vis[i]) v.pb(i);
    }
    
    
}

int dp[1300][N];

int goriber_dp(int idx,int ache) {

    if(ache==0) return 0;
    if(idx>=v.size() || ache-v[idx]<0) return -1e9;
    


    int &ans = dp[idx][ache];
    if(ans!=-1) return ans;
    ans = max(ans, goriber_dp(idx+1, ache));

    if(ache-v[idx]>=0) {
        ans = max(ans, goriber_dp(idx+1, ache-v[idx])+1);
    }
    return ans;
}

int32_t main() {
    fastio;
    
    sieve();
    memset(dp, -1, sizeof dp);
    int t;
    cin>>t;
    while (t--)
    {
        int n; cin>>n;
        cout<<max(0, goriber_dp(0,n))<<endl;
    }
    

    
    return 0;
}

// https://toph.co/p/unique-relief
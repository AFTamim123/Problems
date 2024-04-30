// https://codeforces.com/problemset/problem/382/B

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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define lcm(a,b) (a*b)/__gcd(a,b)
#define int long long 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define N 1000009

void solve() {
    int n;
    cin>>n;
    vl v(n);
    inv(v);
    int one=0;
   
    for (int i = 0; i < n; i++)
    {
        if(v[i]==1) one++;
        else break;
    }
    

    if(one==n) {
        if(one&1) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    else {
        if(one&1) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}
int32_t main() {
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    

    return 0;
}

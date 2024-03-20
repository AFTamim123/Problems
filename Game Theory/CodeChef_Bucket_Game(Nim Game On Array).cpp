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
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>



void solve() {
    int n;
    cin>>n;
    vl v(n);
    inv(v);
    sort(all(v));
    int odd=0,even=0,one=0;
    
    for (int i = 0; i < n; i++)
    {
        if(v[i]==1) one++;
        if(v[i]&1) odd++;
    }
    int a = 0,b=0;
    char move='A';
    a+=(one+1)/2,b=one/2;
    if(odd&1) move='B';

    if(move=='B') a+=n-one;
    else b+=n-one;
    

    if(a>b) cout<<"Alice"<<endl;
    else if(b>a) cout<<"Bob"<<endl;
    else cout<<"Draw"<<endl;
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
https://www.codechef.com/problems/BGME?tab=statement
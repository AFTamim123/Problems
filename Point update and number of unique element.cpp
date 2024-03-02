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
using namespace std;
using namespace __gnu_pbds;
bool check(string s) {
    int lo=0,hi=s.size()-1;
    while (lo<=hi)
    {
        if(s[lo]!=s[hi]) 
            return false;
        lo++,hi--;
    }
    return true;
}
void solve() {
    int n,q;
    cin>>n>>q;
    vl v(n, 0);
    map<int,int> m;
    m[0]+=n;
    while (q--)
    {
        int pos,val;
        cin>>pos>>val;
        pos--;
        m[v[pos]]--;
        if(m[v[pos]]==0)
            m.erase(v[pos]);
        v[pos]+=val;
        m[v[pos]]++;
        cout<<m.size()<<endl;
    }
    
    
}

int32_t main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


https://atcoder.jp/contests/abc343/tasks/abc343_d

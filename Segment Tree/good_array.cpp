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
#define lcm(a,b) (a*b)/__gcd(a,b)
using namespace std;
using namespace __gnu_pbds;

int calc(int n) {
    return n*(n+1)/2;
}

class sgtree{
    vector<int> seg;
public:
    sgtree(int n) {
        seg.resize(4*n);
    }
    void build(int ind, int low, int high, vector<int> &arr) {
        if(low==high) {
            seg[ind]=arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }
    int query(int ind, int low, int high, int l,int r) {
        if(r<low || high<l) return INT_MIN;
        if(low>=l && high<=r) return seg[ind];
        int mid = (low+high)/2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return max(left, right);
    }
};


void solve() {
    int n;
    cin>>n;
    vl v(n);
    inv(v);
    sgtree tr(n);
    tr.build(0,0,n-1, v);
    int tsum = accumulate(all(v), 0LL);
    vl ans;
    for (int i = 0; i < n; i++)
    {
        int sum = tsum-v[i];
        if(i==0) {
            int ma = tr.query(0,0,n-1,1,n-1);
            sum-=ma;
            if(ma==sum) ans.pb(i+1);
        } 
        else if(i==n-1) {
            int ma = tr.query(0,0,n-1,0,i-1);
            sum-=ma;
            if(ma==sum) ans.pb(i+1);
        }
        else {
            int ma = max(tr.query(0,0,n-1,0,i-1), tr.query(0,0,n-1,i+1,n-1));
            sum-=ma;
            if(ma==sum) ans.pb(i+1);
        }
    }
    cout<<ans.size()<<endl;
    outv(ans);
    
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
// https://codeforces.com/problemset/problem/1077/C
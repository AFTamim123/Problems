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
#define outv(a) for(auto &it : a) cout << it << " ";cout<<endl
#define outv1(a) for(auto &it : a) cout << it << " "<<endl;cout<<endl
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
using namespace std;
// typedef __gnu_pbds::tree<
// int, 
// __gnu_pbds::null_type,
// less<int>, __gnu_pbds::rb_tree_tag,
// __gnu_pbds::tree_order_statistics_node_update>
// ordered_set;
// ll binpow(ll a, ll b, ll MOD) {
//     ll result = 1;
//     while (b > 0) {
//         if (b % 2 == 1) result = (result * a) % MOD;
//         a = (a * a) % MOD;
//         b /= 2;
//     }
//     return result % MOD;
// }

class sgtree{
    vector<int> seg;
    int n;
public:
    sgtree(int n): n(n) {
        seg.resize(4*n);
    }
    void build(int ind, int low, int high, int arr[]) {
        if(low==high) {
            seg[ind]=arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = __gcd(seg[2*ind+1],seg[2*ind+2]);
    }
    int query(int ind, int low, int high, int l,int r) {
        // 1. NO overlap
        // l r low high || low high l r
        if(r<low || high<l) return 0;
        // 2.  complete overlap
        if(low>=l && high<=r) return seg[ind];
        // 3. partial overlap
        int mid = (low+high)/2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return __gcd(left,right);
    }
    void update(int ind, int low, int high, int i, int val) {
        if(low==high) {
            seg[ind] = val;
            return;
        }
        int mid = (low+high)/2;
        if(i<=mid) update(2*ind+1, low, mid, i,val);
        else update(2*ind+2, mid+1, high, i, val);
        seg[ind]= __gcd(seg[2*ind+1],seg[2*ind+2]);
    }
    bool check(int l, int r, int x) {
        while (l<=r)
        {
            int mid = (l+r)/2;
            int a = query(0,0,n-1,l,mid);
            int b = query(0,0,n-1,mid+1,r);
            if(a%x>0 && b%x>0) return false;
            else if(a%x>0) r=mid-1;
            else if(b%x>0) l=mid+1;
            else return true;
        }
        return true;
    }
};



void solve(int tc) {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sgtree tr(n);
    tr.build(0,0,n-1,arr);
    int q;
    cin>>q;
    while (q--)
    {
        int a; cin>>a;
        if(a==1) {
            int l,r,x;
            cin>>l>>r>>x;
            if(tr.check(l-1,r-1,x)) yes;
            else no;
        }
        else {
            int pos,val;
            cin>>pos>>val;
            tr.update(0,0,n-1,pos-1,val);
        }
    }
    
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t =1;
    // int t;
    // cin>>t;

    for (int T = 1; T <= t; T++)
    {
        solve(T);
    }
    
    


    return 0;
}

https://codeforces.com/contest/914/problem/D

// Learning we can recursive check every node.
// dont use endl and long long unnesessarily
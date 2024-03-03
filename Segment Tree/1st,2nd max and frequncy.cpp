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

struct node{
    int mx1=-1,mx2=-1,c1=0,c2=0;  
};

class sgtree{
    vector<node> seg;
public:
    sgtree(int n) {
        seg.resize(4*n);
    }
    node merge(node l, node r) {
        map<int,int,greater<int>> m;
        node res;

        m[l.mx1]+=l.c1;
        m[l.mx2]+=l.c2;
        m[r.mx1]+=r.c1;
        m[r.mx2]+=r.c2;

        res.mx1=m.begin()->first;
        res.c1=m.begin()->second;
        res.mx2=next(m.begin())->first;
        res.c2=next(m.begin())->second;

        return res;

    }
    void build(int ind, int low, int high, int arr[]) {
        if(low==high) {
            node c;
            c.c1=1,c.mx1=arr[low];
            seg[ind]=c;
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = merge(seg[2*ind+1], seg[2*ind+2]);
    }
    node query(int ind, int low, int high, int l,int r) {
        // 1. NO overlap
        // l r low high || low high l r
        if(r<low || high<l) {
            node c;
            return c;
        }
        // 2.  complete overlap
        if(low>=l && high<=r) return seg[ind];
        // 3. partial overlap
        int mid = (low+high)/2;
        node left = query(2*ind+1, low, mid, l, r);
        node right = query(2*ind+2, mid+1, high, l, r);
        return merge(left, right);
    }
    void update(int ind, int low, int high, int i, int val) {
        if(low==high) {
            seg[ind].mx1=val;
            seg[ind].c1=1;
            seg[ind].mx2=-1;
            seg[ind].c2=0;
            return;
        }
        int mid = (low+high)/2;
        if(i<=mid) update(2*ind+1, low, mid, i,val);
        else update(2*ind+2, mid+1, high, i, val);
        seg[ind]= merge(seg[2*ind+1], seg[2*ind+2]);
    }
};


void solve() {
    int n,q;
    cin>>n>>q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sgtree tr(n);
    tr.build(0,0,n-1,arr);
    while (q--)
    {
        int a; cin>>a;
        if(a==1) {
            int p,x;
            cin>>p>>x;
            p--;
            tr.update(0,0,n-1,p,x);
        }
        else {
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<tr.query(0,0,n-1,l,r).c2<<endl;
        }
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



https://atcoder.jp/contests/abc343/tasks/abc343_f
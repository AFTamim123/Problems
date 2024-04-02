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
#define int long long
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
class sgtree{
    vector<int> seg;
public:
    sgtree(int n) {
        seg.resize(4*n);
    }
    void build(int ind, int low, int high, vi &arr) {
        if(low==high) {
            seg[ind]=arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = (seg[2*ind+1]+seg[2*ind+2]);
    }
    int query(int ind, int low, int high, int l,int r) {
        if(r<low || high<l) return 0;
        if(low>=l && high<=r) return seg[ind];
        int mid = (low+high)/2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return left+right;
    }
    void update(int ind, int low, int high, int i, int val) {
        if(low==high) {
            seg[ind] = val;
            return;
        }
        int mid = (low+high)/2;
        if(i<=mid) update(2*ind+1, low, mid, i,val);
        else update(2*ind+2, mid+1, high, i, val);
        seg[ind]= (seg[2*ind+1]+seg[2*ind+2]);
    }
};

 
int32_t main() {
    fastio;
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    
    
    int n,q;
    cin>>n>>q;
    vl v(n);
    inv(v);
    sgtree tr(n);
    tr.build(0,0,n-1, v);

    while (q--)
    {
        int x; cin>>x;
        if(x==1) {
            int pos,val;
            cin>>pos>>val;
            pos--;
            tr.update(0,0,n-1,pos,val);
        }
        else {
            int l,r;
            cin>>l>>r;
            l--,r--;
            int ache = 0;
            int lo=l,hi=r;
            while (lo<=hi)
            {
                int mid = (lo+hi)>>1LL;
                int sum = tr.query(0,0,n-1,l,mid);
                if(sum<=(mid-l+1)) {
                    ache = mid-l+1;
                    lo=mid+1;
                }
                else hi = mid - 1;
            }
            // cout<<ache<<endl;
            if(ache==(r-l+1)) {
                if(ache&1) cout<<"First"<<endl;
                else cout<<"Second"<<endl;
            }
            else {
                if(ache&1) cout<<"Second"<<endl;
                else cout<<"First"<<endl;
            }
        }
    }
    
    return 0;
}
// https://codeforces.com/gym/104283/problem/H
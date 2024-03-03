// By the name of ALLAH, The Creator of the Universe
#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long>
#define debug cout << "KI OBOSTA BOSS!" << endl
#define ll long long
#define F first
#define S second
#define inv(a) for(auto &it : a) cin >> it;
#define outv(a) for(auto &it : a) cout << it << " ";cout<<endl
#define pb push_back
#define all(v) v.begin(), v.end()
#define mod 1000000007
using namespace std;

string s;
const int N = 1e6+2;
struct node {
    int open,close,full;
};
node tree[4*N];
node merge(node l, node r) {
    node notun;
    notun.full = l.full+r.full+min(l.open, r.close);
    notun.open = l.open+r.open-min(l.open, r.close);
    notun.close = l.close+r.close-min(l.open, r.close);
    return notun;
}
node query(int ind, int b, int e, int i, int j) {
    if(j<b || e<i) {
        node ans;
        ans.open=0,ans.close=0,ans.full=0;
        return ans;
    }
    if(b>=i && e<=j) return tree[ind];
    int mid = (b+e)>>1;
    return merge(
        query(2*ind+1, b, mid, i, j),
        query(2*ind+2, mid+1, e, i, j)
    );   
}
void build(int ind, int b, int e) {
    if(b==e) {
        if(s[b]=='(') tree[ind].open=1,tree[ind].close=0,tree[ind].full=0;
        else tree[ind].open=0,tree[ind].close=1,tree[ind].full=0;
        return;
    }
    int left = ind*2+1;
    int right = ind*2+2;
    int mid = (b+e)>>1;
    build(left, b,mid);
    build(right, mid+1,e);
    tree[ind]=merge(tree[left],tree[right]);
}
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin>>s;
    int n;
    n=s.size();
    build(0,0,n-1);
    node ans = query(0,0,n-1,0,n-1);
    cout<<ans.full*2<<endl;
    
    return 0;
}

https://codeforces.com/problemset/problem/26/B
https://codeforces.com/contest/380/problem/C
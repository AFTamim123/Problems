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
#define inf LONG_LONG_MAX
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define lcm(a,b) (a*b)/__gcd(a,b)
#define int long long
#define inf LONG_LONG_MAX

void solve() {
    int n;
    cin>>n;
    int arr[n];
    vi tr[n];
    vl odd,even;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(arr[i]&1) odd.pb(i);
        else even.pb(i);
    }
    for (int i = 0; i < n; i++)
    {
        int l = i-arr[i];
        int r = i+arr[i];

        if(l>=0) tr[l].pb(i);
        if(r<n) tr[r].pb(i);
    }
  
    vl ans(n, inf);
    vl ans1(n, inf);
    vl res(n, -1);
    queue<int> q;

    vl vis(n,0);
    for (int i = 0; i < even.size(); i++)
        q.push(even[i]),ans[even[i]]=0,vis[even[i]]=1;
    

    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for(auto it: tr[p]) {
            if(vis[it]) continue;
            vis[it]=1;
            q.push(it);
            ans[it]=min(ans[it], ans[p]+1);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if(ans[i]!=inf && ans[i]!=0) 
            res[i]=ans[i];
    }
    

    vl vis1(n,0);
    for (int i = 0; i < odd.size(); i++)
        q.push(odd[i]),ans1[odd[i]]=0,vis1[odd[i]]=1;
    
    
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for(auto it: tr[p]) {
            if(vis1[it]) continue;
            vis1[it]=1;
            q.push(it);
            ans1[it]=min(ans1[it], ans1[p]+1);
        }
    }
    
    

    for (int i = 0; i < ans1.size(); i++)
    {
        if(ans1[i]!=inf && ans1[i]!=0) 
            res[i]=ans1[i];
    }
   
    outv(res);
    
   

    
}





int32_t main() {
    fastio;
   
    int T=1;
    // cin>>T;
    while (T--)
    {
        solve();
    }
    

    return 0;
}

// https://codeforces.com/contest/1272/problem/E
// https://leetcode.com/problems/as-far-from-land-as-possible/description/
// https://www.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves
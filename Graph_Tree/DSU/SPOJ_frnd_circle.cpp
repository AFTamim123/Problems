#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)



class DSU {
    vector<int> size,parent,rank;
public:
    DSU(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int finduparent(int node) {
        if(node==parent[node]) 
            return node;
        return parent[node] = finduparent(parent[node]);
    }
    void unionbyrank(int u, int v) {
        int u_parent = finduparent(u);
        int v_parent = finduparent(v);
        if(u_parent==v_parent) return;
        if(rank[v_parent]>rank[u_parent]) {
            parent[u_parent]=v_parent;
        }
        else if(rank[v_parent]<rank[u_parent]) {
            parent[v_parent]=u_parent;
        }
        else {
            parent[v_parent]=parent[u_parent];
            rank[u_parent]++;
        }
    }
    void unionbysize(int u, int v) {
        int u_parent = finduparent(u);
        int v_parent = finduparent(v);
        if(u_parent==v_parent) return;
        if(size[v_parent]>size[u_parent]) {
            parent[u_parent]=v_parent;
            size[v_parent]+=size[u_parent];
        }
        else {
            parent[v_parent]=u_parent;
            size[u_parent]+=size[v_parent];
        }
    }
 
    int getSize(int node) {
        return size[finduparent(node)];
    }
};

void solve(int tc) {
    int n;
    cin >> n;
    map<string,int> mp;
    vector<pair<int,int>> p;
    int c = 0,ma=0;
    for (int i = 0; i < n; i++) {
        string u, v;
        cin >> u >> v;
        int a = 0, b = 0;
        
        if (!mp[u]) {
            c++;
            mp[u] = c;
        }
        if (!mp[v]) {
            c++;
            mp[v] = c;
        }
        a = mp[u], b = mp[v];
        p.push_back({a, b});
        ma=max(ma, a);
        ma=max(ma, b);
    }
    
    DSU tr(ma+1);

    for (int i = 0; i < n; i++)
    {
        int u = p[i].first,v=p[i].second;
       
        tr.unionbysize(u,v);
        cout<<tr.getSize(v)<<endl;
    }
    
}

int main() {
    fastio;
    
    int tc=1;
    cin>>tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }
    
    return 0;
}

// https://www.spoj.com/problems/FRNDCIRC/
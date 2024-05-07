#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
using namespace std;

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

    int anskoto(int node) {
        int ul_parent = finduparent(node);
        return size[ul_parent];
    }
};





int32_t main() {

    int n,k; cin>>n>>k;
    DSU ds(n);

    while (k--)
    {
        int g; cin>>g;
        vector<int> v(g);
        for (int i = 0; i < g; i++)
        {
            cin>>v[i];
        }
        if(v.size()<2) continue;

        for (int i = 0; i < g-1; i++)
        {
            ds.unionbysize(v[i], v[i+1]);
        }   
    }

    for (int i = 1; i <= n; i++)
    {
        cout<<ds.anskoto(i)<<" ";
    }
    cout<<endl;
    
    
	return 0;
}
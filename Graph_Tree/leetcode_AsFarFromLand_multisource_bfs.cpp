// بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvalid(int n, int x, int y) {
        return x>=0 && y>=0 && x<n && y<n;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int vis[n][n];
        int level[n][n];

        vector<pair<int,int>> move = {{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>> q;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j]==1) {
                    q.push({i,j});
                    vis[i][j]=1;
                    level[i][j]=0;
                }
                else {
                    vis[i][j]=0;
                    level[i][j]=200;
                }
            }
        }
        int ans = -1;
        while(!q.empty()) {
            auto p = q.front();
            int px = p.first,py=p.second;
            q.pop();
            for(auto it: move) {
                int cx = px+it.first,cy=py+it.second;
                if(!isvalid(n,cx,cy)) continue;
                if(!vis[cx][cy]) {
                    q.push({cx,cy});
                    vis[cx][cy]=1;
                    level[cx][cy]=min(level[cx][cy], level[px][py]+1);
                    ans = max(ans, level[cx][cy]);
                }
            }
        }
        return ans;
    }
};



int32_t main() {
   
   
    
    
    return 0;
}
// https://leetcode.com/problems/as-far-from-land-as-possible/description/
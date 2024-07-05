// بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
// #define int long long

const int N = 5e3+2;
int n;
int dp[N][N];
vector<int> v;

int koro(int idx, int m) {
    if(idx==n) return 0;
    int &ret = dp[idx][m];
    if(ret!=-1) return ret;

    ret = koro(idx+1, m+1);
    if(m-v[idx]>=0) {
        ret = max(ret, 1+koro(idx+1, m-v[idx]));
    }
    return ret;
}

void solve(int TC) {
    v.clear();
    cin>>n;
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        int x; cin>>x;
        mp[x]++;
    }
    for(auto &it: mp) v.push_back(it.second);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j]=-1;
        }
    }
    n=v.size();
    cout<<v.size()-koro(0,0)<<endl;
}

int32_t main() {
    fastio;

    int tc; 
    cin >> tc;
    for (int TC = 1; TC <= tc; TC++) {
        solve(TC);
    }

    return 0;
}

// https://codeforces.com/contest/1987/problem/D
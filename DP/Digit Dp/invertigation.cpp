// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<long long> 
#define vi vector<int>
#define F first
#define S second
#define inv(a) for (auto &it : a) cin >> it;
#define outv(a) for (auto &it : a) cout << it << " "; cout << "\n";
#define outv1(a) for (auto &it : a) cout << it << endl;
#define pb push_back
#define all(v) v.begin(), v.end()
#define pp pop_back()
#define rall(v) v.rbegin(), v.rend()
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int gcd(int a, int b) {return __gcd(a,b);}
// #define  int long long

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
// int my_rand(int a, int b) {
//     if (a > b) return 0;
//     return a + rng() % (b - a + 1);
// }

string l,r,s;
int sz,mod;
int dp[10][2][100][90];

int marodp(int idx, int isSmall, int rem, int rem1) {
    
    if(idx==sz) {
        return rem==0 && rem1==0;
    }

    int lim = 9;
    int digit = s[idx]-'0';
    if(!isSmall) lim = digit;

    int &ans = dp[idx][isSmall][rem][rem1];
    if(ans!=-1) return ans;
    ans = 0;
    for (int i = 0; i <= lim; i++)
    {
        ans += marodp(idx+1, isSmall|(i<digit), (rem*10+i)%mod, (rem1+i)%mod);
    }
    return ans;
}

void reset() {
    memset(dp, -1, sizeof dp);
}


int thikase(string s) {
    int ans = 0,sum=0;
    for (int i = 0; i < s.size(); i++)
    {
        ans=ans*10+(s[i]-'0');
        sum+=(s[i]-'0');
        ans %=mod;
        sum%=mod;
    }
    return ans==0 && sum==0;
    
}
void solve(int t) { 
    cin>>l>>r>>mod;
    if(mod>=90) {
        cout<<"Case "<<t<<": "<<0<<endl;
        return;
    }
    reset();
    s=r;
    sz=s.size();
    int ans = marodp(0,0,0,0);

    reset();
    s=l;
    sz=s.size();
    ans -= marodp(0,0,0,0);
    
    cout<<"Case "<<t<<": "<<ans+thikase(l)<<endl;
}

int32_t main() {
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t=1;
    cin>>t;
    for (int i = 1; i<=t; i++)
    {
        solve(i);
    }
    
    
    return 0;
}


// https://lightoj.com/problem/investigation

// بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define u128 unsigned __int128
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)


u128 bin_expo(u128 a, u128 b, u128 mod) {
    u128 result = 1;
    while (b > 0) {
        if (b % 2 == 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result % mod;
}

void solve(int TC) {
    
    string a1,b1,s; 
    cin>>a1>>b1>>s;

    u128 a=0,b=0,m=0;
    for(auto &it: a1) a = a*10+(it-'0');
    for(auto &it: b1) b = b*10+(it-'0');
    for(auto &it: s) m = m*10+(it-'0');

    u128 ans = bin_expo(a,b,m);
    string res="";
    while (ans>0)
    {
        res += ((ans%10)+'0');
        ans/=10;
    }
    reverse(res.begin(), res.end());

    if(res.empty())  res = "0";
    cout<<res<<endl;
    // cout<<ans<<endl;
    
}


int32_t main() {
    fastio;
    
    int tc = 1; 
    cin >> tc;
    for (int TC = 1; TC <= tc; TC++) {
        solve(TC);
    }

    return 0;
}

// https://www.spoj.com/problems/PWRANDMOD/

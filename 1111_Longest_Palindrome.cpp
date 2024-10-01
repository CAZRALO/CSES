#include <bits/stdc++.h>
#define el '\n'
#define sp ' '
#define int long long
#define ms(a,val) memset(a,val,sizeof(a))
#define all(a) a.begin(),a.end()
#define sz(a) (int) a.size()
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define FAST { ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0); }
using namespace std;
# pragma GCC target("avx")
# pragma GCC target("avx2")
# pragma GCC target("fma")
# pragma GCC optimize("Os")
# pragma GCC optimize("Ofast")
# pragma GCC optimization ("03")
# pragma GCC optimization ("unroll-loops")
 
int n;
int dp[1000005][2] = {0};
 
signed main() {
    FAST
    string s;
    cin>>s;
    if (sz(s)==1) {
        cout<<s;
        return 0;
    }
    n=sz(s);
    int x1 = 0, y1 = -1;
    int x2 = 0, y2 = -1;
    int mx = 0, ans = 0;
    fo(i,1,n) {
        int k = 0;
        if (i>y1)  k = 1;
        else k = min(dp[x1+y1-i][0], y1-i+1);
        while (0<=i-k && i+k<n && s[i-k] == s[i+k]) k++;
 
        dp[i][0] = k--;
        if (i+k>y1) x1 = i-k, y1 = i+k;
        if (2*dp[i][0] - 1 > mx) ans = i-k, mx = 2*dp[i][0] - 1;
        k = 0;
        if (i<=y2) k = min(dp[x2+y2-i+1][1],y2-i+1);
 
        while(0<=i-k-1 && i+k<n && s[i-k-1] == s[i+k]) k++;
        dp[i][1] = k--;
        if (i+k>y2) x2 = i-k-1, y2 = i+k;
 
        if (2*dp[i][1] > mx) ans = i-k-1, mx = 2*dp[i][1];
    }
    cout<<s.substr(ans,mx);
    return 0;
}

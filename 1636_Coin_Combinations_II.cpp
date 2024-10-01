#include <bits/stdc++.h> 
using namespace std; 
 
#define int long long
 
const int MOD=1e9+7;
 
int n,x;
int coin[105];
int dp[1000005];
int res;
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>x;
    for (int i=1;i<=n;++i){
        cin>>coin[i];
    }
    dp[0]=1;
    for (int i=1;i<=n;++i) {
        for (int weight=1;weight<=x;++weight) {
            if (weight-coin[i]>=0){
                dp[weight]+=dp[weight-coin[i]];
                dp[weight]%=MOD;
            }
        }
    }
    cout<<dp[x];
    return 0; 
}

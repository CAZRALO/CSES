#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
 
#define el '\n'
#define sp ' '
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ph push
#define mp make_pair
#define all(a) a.begin(),a.end()
#define PB pop_back()
#define PF pop_front()
#define tostr to_string
#define lth length()
#define mty empty()
#define lb lower_bound
#define ub upper_bound
#define str string
#define ll unsigned long long
#define debug(x) cout<<x<<el;
#define ms(a,val) memset(a,val,sizeof(a))
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fr(i,a,b) for(int i=a;i>=b;--i)
#define FO(i,a,b,x) for (ll i=a;i<=b;i+=x)
#define FR(i,a,b,x) for (ll i=a;i>=b;i-=x)
#define FAST ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
 
using namespace std;
 
# pragma GCC target("avx")
# pragma GCC target("avx2")
# pragma GCC target("fma")
# pragma GCC optimize("Os")
# pragma GCC optimize("Ofast")
# pragma GCC optimization ("03")
# pragma GCC optimization ("unroll-loops")
 
signed main(int argc, char *argv[]){
    FAST
    int t;
    ll x,y;
    cin>>t;
    while (t--) {
        cin>>x>>y;
        ll res;
        ll minnum=(max(x,y)-1)*(max(x,y)-1);
        ll maxnum=max(x,y)*max(x,y);
        if (x>y) {
            if (x&1) {
                debug(minnum+y)
            } else {
                debug(maxnum-y+1)
            }
        } else {
            if (y&1) {
                debug(maxnum-x+1)
            } else {
                debug(minnum+x)
            }  
        }
    }
    return 0;
}

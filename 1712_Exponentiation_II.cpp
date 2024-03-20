# include <bits/stdc++.h>

# define x first
# define y second
# define int long long

using namespace std;

const int MOD=1e9+7;

template<class T> T expo(T a, T b,T p){
    int res=1;
    a%=p;
    while (b) {
        if (b&1) {
            res=(res*a)%p;
        }
        b>>=1;
        a=(a*a)%p;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);;
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    while (n--){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<expo(a,expo(b,c,MOD-1),MOD)<<'\n';
    }
    return 0;
}

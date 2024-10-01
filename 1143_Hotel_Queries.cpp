#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define L cout<<'\n';
#define E cerr<<'\n';
#define all(x) x.begin(),x.end()
#define fu(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
const ll inf = 1LL<<62;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
 
const int N = 2000005;
int ST[2*N],n;
void update(int pos, int val) {
    for (ST[pos += n] = val; pos >= 1; pos >>= 1) {
        ST[pos>>1]=max(ST[pos], ST[pos^1]);
    }
}
int query(int val) {
    if (ST[1]<val) return 0;
    int pos = 1;
    for (;pos <= n;) {
        if (ST[pos<<1]>=val) pos <<= 1;
        else pos = pos << 1 | 1;
    }
    return pos-n;
}
 
void solve(){
    int m; see(n,m);
    int nn=n;
    n=ceil(log2(n*1.0));
    n=1<<n;
    fu(i,1,nn) {
        int x;
        cin>>x;
        update(i,x);
    }
    while (m--) {
        int r;
        cin >> r;
        int id=query(r);
        put(id); 
        if (id) update(id,ST[id+n]-r);
    }
}    
signed main(){
    IOS;
    solve();
}

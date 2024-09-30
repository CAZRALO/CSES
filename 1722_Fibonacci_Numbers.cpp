#include<bits/stdc++.h>
using namespace std;

#define tcT template <class T
#define tcTU tcT, class U

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define int long long
#define fi first
#define se second
#define str string
#define all(a) a.begin(), a.end()
#define pb push_back
#define ins insert
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define fu(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define f0u(i,b)  for(int i=0;i<b;++i)
#define f0d(i,b)  for(int i=(b)-1;i>=0;--i)
#define FU(i,a,b,x) for (int i=a;i<=b;i+=x)
#define FD(i,a,b,x) for (int i=a;i>=b;i-=x)
#define trav(a, x) for (auto &a : x)
#define pii pair<int,int>

const int MOD=1e9+7;
const int N=1e5;
const signed dx[4] = {1, 0, -1, 0},
             dy[4] = {0, 1, 0, -1};

tcT>inline T gcd(T a,T b) { while (b != 0) swap(b, a %= b); return a; }
tcT>inline T lcm(T a,T b) { return a / gcd(a, b) * b; }
tcT>inline tuple<T,T,T> extgcd(T a,T b) {
    if(a==0)return mt(b,0,1);
    T g,x,y;
	tie(g,x,y)=extgcd(b%a,a);
    return mt(g,y-(b/a)*x,x);
}
tcT > bool minimize(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
tcT > bool maximize(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
tcT > void add(T &a, const T &b) { a+=b; if (a>MOD) a-=MOD; }
tcT > void multiply(T &a, const T &b) { a=(a*b)%MOD; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int ctz(int x) { return __builtin_ctzll(x); }
constexpr int clz(int x) { return __builtin_clzll(x); }
constexpr int bits(int x) {  // assert(x >= 0);
	return x == 0 ? 0 : 31 - __builtin_clz(x);
}  // floor(log2(x))
constexpr int MASK(int x) { return 1ll << (x); }

void power(int F[2][2],int n);
void multiply(int F[2][2], int M[2][2]);

int fibo(int n){
    if (n==0) {
        return 0;
    }
    int F[2][2]={ {1 , 1} , {1 , 0} };
    power(F,n);
    return F[0][0]%MOD;
}

void power(int F[2][2], int n) {
    if (n==1 || n==0) {
        return;
    }
    int M[2][2]={ {1 , 1} , {1 , 0} };
    power(F,n>>1);
    multiply(F,F);

    if (n&1) {
        multiply(F,M);
    }
}

void multiply(int F[2][2], int M[2][2]) {

    int x = ( (F[0][0]*M[0][0])%MOD + (F[0][1]*M[1][0]) %MOD )%MOD;
    int y = ( (F[0][0]*M[0][1])%MOD + (F[0][1]*M[1][1]) %MOD )%MOD;
    int z = ( (F[1][0]*M[0][0])%MOD + (F[1][1]*M[1][0]) %MOD )%MOD;
    int w = ( (F[1][0]*M[0][1])%MOD + (F[1][1]*M[1][1]) %MOD )%MOD;

    F[0][0] = x; F[0][1] = y;
    F[1][0] = z; F[1][1] = w;
}
void solve() {
}

signed main(signed argc, char *argv[]) {
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr); cout.tie(nullptr);
    int t=1;
    //see(t);
    while (t--) {
        solve();
    }
    return 0;
}

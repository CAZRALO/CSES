#include<bits/stdc++.h>
using namespace std;
 
#define st first
#define nd second
#define int long long
#define str string
#define MASK(x) (1ll<<x)
#define bg begin()
#define end end()
#define rbg rbegin()
#define rend rend()
#define all(a) a.bg, a.end
#define rall(a) a.rbg, a.rend
#define pb push_back
#define ins insert
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
 
const int MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};
const long long inf = LLONG_MAX; 
const signed N = 2e5+5;
 
void setIO() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr); cout.tie(nullptr);
    bool check = 0;
    //check = 1;
    if (check) {
        freopen("chiaphong.inp","r",stdin);
        freopen("chiaphong.out","w",stdout);
    }
}
 
int a[N];
int n,m;
 
class SegmentTree {
private : 
    vector<int>tree;
    void build(int node, int l, int r) {
        if (l > r) return;
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid);
        build(node << 1 | 1, mid + 1, r);
        tree[node] = max(tree[node << 1],tree[node << 1 | 1]);
    }
    void update(int node, int l, int r, int i, int val) {
        if (i > r || i < l) return;
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(node << 1, l, mid, i, val);
        update(node << 1 | 1, mid + 1, r, i, val);
        tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }
    int query(int node, int l,int r, int u,int v, int val) {
        if (v < l || r < u) return -1;
        if (u <= l && r <= v) {
            if (tree[node] < val) return -1;
            while (l != r){
                int mid = (l + r) >> 1;
                if (tree[node << 1] >= val) node <<= 1, r = mid;
                else node = node << 1 | 1, l = mid + 1;
            }
            return l;
        }
        int mid = (l + r) >> 1;
        int value = query(node << 1, l, mid, u, v, val);
        return (value != -1 ? value : query(node << 1, mid + 1, r, u, v, val));
    }
public : 
    SegmentTree() {
        tree.resize(n << 2);
        build(1, 1, n);
    }
    int findFirstGreaterOrEqual(int l, int r, int val) {
        return query(1, 1, n, l, r, val);
    }
    void update(int idx, int val) {
        update(1, 1, n, idx, val);
    }
};
void solve() {
    cin >> n >> m;
    fu(i,1,n) cin >> a[i];
    SegmentTree st;
    int numOfVisitors;
    fu(i,1,m) {
        cin >> numOfVisitors;
        int idx = st.findFirstGreaterOrEqual(1,n,numOfVisitors);
        if (idx != -1) {
            cout << idx << ' ';
            a[idx] -= numOfVisitors;
            st.update(idx,a[idx]);
        } else cout << "0 ";
    }
}
 
signed main(signed argc, char *argv[]) {
    setIO();
    solve();
    return 0;  
}

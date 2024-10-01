#include<bits/stdc++.h>
 
using namespace std;
 
//#define int long long
 
class SegT{
    private:
        int N;
        vector<int>T;
        void update(int id, int l, int r, int i, int val) {
            if (l > i || r < i) return;
            if (l == r) {
                T[id] = val;
                return;
            }
            int m=(l + r) >> 1;
            if (i<=m) {
                update(id<<1, l, m, i, val);
            } else {
                update(2 * id + 1, m + 1, r, i, val);
            }
            T[id] = min(T[2 * id] , T[2 * id + 1]);
        }
        int query(int id,int l,int r,int u,int v) {
            if (r<u || v<l) return INT_MAX;
            if (u<=l && r<=v) return T[id];
            int m=(l+r) >> 1;
            return min(query(id<<1,l,m,u,v),query((id*2)+1,m+1,r,u,v));
        }
 
public:
    SegT() {}
    SegT(int n) : N(n), T(4*n+5,INT_MAX) {}
    void upd(int i,int val) { update(1,1,N,i,val); }
    int query(int l,int r) { return query(1,1,N,l,r); }
};
 
SegT upT,downT;
int n,q;
vector<int> A(200000+5);
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>q;
    for (int i=1;i<=n;++i) cin>>A[i];
    upT=downT=SegT(n);
    for (int i=1;i<=n;++i) {
        upT.upd(i,A[i]+i);
        downT.upd(i,A[i]-i);
    }
    while (q--) {
        int k,a,b;
        cin>>k;
        if (k==1) {
            cin>>a>>b;
            upT.upd(a,a+b);;
            downT.upd(a,b-a);
        } else {
            cin>>a;
            cout<<min(upT.query(a,n)-a,downT.query(1,a)+a)<<endl;
        }
    }
    return 0;
}

#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
struct line{
    LL x1,x2,h,op,z;
    bool operator <(const line& rhs) const {
        if (z == rhs.z) return h < rhs.h;
        return z < rhs.z;
    }
};
struct node{
    LL l,r,val,len[12];
};
LL n,K;
node a[800100];
line E[400100];
LL V[200100];
void build(int l,int r,int k) {
    a[k].l = l;a[k].r = r;a[k].len[0] = V[r] - V[l];
    if (l + 1 >= r) return;
    int mid = (l + r) >> 1;
    build(l,mid,k<<1);
    build(mid,r,k<<1|1);
}
void push(int k) {
    for (int i = 0;i <= K+1; i++) a[k].len[i] = 0;
    if (a[k].l + 1 >= a[k].r) a[k].len[min(K+1,a[k].val)] = V[a[k].r] - V[a[k].l];
    else {
        for (int j = 0;j <= K+1; j++) {
            a[k].len[min(K+1,j+a[k].val)] += a[k<<1].len[j] + a[k<<1|1].len[j];
        }
    }
}
void updata(int x,int y,int k,int op) {
    if (x <= a[k].l && a[k].r <= y) {
        a[k].val += op;
        push(k);
        return;
    }
    int mid = (a[k].l + a[k].r) >> 1;
    if (x < mid) updata(x,y,k<<1,op);
    if (y > mid) updata(x,y,k<<1|1,op);
    push(k);
}
int main() {
    cin >> n >> K;
    int cnt = 0,ecnt = 0;
    LL x1,y1,z1,x2,y2,z2;
    for (int i = 1;i <= n; i++) {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        if (z1 == 1 && z2 > 1) {
            E[ecnt++] = (line){x1,x2,y1,1,0};
            E[ecnt++] = (line){x1,x2,y2,-1,0};
        }
        if (z1 < 3 && z2 == 3) {
            E[ecnt++] = (line){x1,x2,y1,1,1};
            E[ecnt++] = (line){x1,x2,y2,-1,1};
        }
        V[++cnt] = x1;V[++cnt] = x2;
    }
    sort(E,E+ecnt);
    sort(V+1,V+cnt+1);
    int m = unique(V+1,V+cnt+1) - V;
    build(1,m-1,1);
    LL ans = 0;
    for (int i = 0;i < ecnt; i++) {
        int x1 = lower_bound(V+1,V+m,E[i].x1) - V;
        int x2 = lower_bound(V+1,V+m,E[i].x2) - V;
        updata(x1,x2,1,E[i].op);
        if (E[i+1].z == E[i].z) ans += (E[i+1].h - E[i].h)*a[1].len[K];
        //cout << (E[i+1].h - E[i].h) << " " << a[E[i].z][1].len[K] << endl;
    }
    printf("%lld\n",ans);
	return 0;
}

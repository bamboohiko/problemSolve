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
const int maxn = 1e5 + 10;
LL t[4*maxn],lazy[4*maxn];
void down(int l,int mid,int r,int k) {
    lazy[k<<1] += lazy[k];t[k<<1] += lazy[k]*(mid-l+1);
    lazy[(k<<1)|1] += lazy[k];t[(k<<1)|1] += lazy[k]*(r-mid);
    lazy[k] = 0;
}
void build(int l,int r,int k) {
    if (l == r) {
        scanf("%lld",&t[k]);
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,k<<1);
    build(mid+1,r,(k<<1)|1);
    t[k] = t[k<<1] + t[(k<<1)|1];
}
void updata(int l,int r,int k,int x,int y,LL val) {
    if (x <= l && r <= y) {
        lazy[k] += val;
        t[k] += (r-l+1)*val;
        return;
    }
    int mid = (l + r) >> 1;
    down(l,mid,r,k);
    if (x <= mid) updata(l,mid,k<<1,x,y,val);
    if (y > mid) updata(mid+1,r,(k<<1)|1,x,y,val);
    t[k] = t[k<<1] + t[(k<<1)|1];
}
LL query(int l,int r,int k,int x,int y) {
    if (x <= l && r <= y) {
        return t[k];
    }
    int mid = (l + r) >> 1;LL s1 = 0,s2 = 0;
    down(l,mid,r,k);
    if (x <= mid) s1 = query(l,mid,k<<1,x,y);
    if (y > mid) s2 = query(mid+1,r,(k<<1)|1,x,y);
    return s1 + s2;
}

int main() {
    int n,m,l,r;LL k;char ch;
    while (scanf("%d%d",&n,&m) != EOF) {
        memset(t,0,sizeof(t));
        memset(lazy,0,sizeof(lazy));
        build(1,n,1);
        getchar();
        for (int i = 1;i <= m; i++) {
            ch = getchar();
            if (ch == 'C') {
                scanf("%d%d%lld%*c",&l,&r,&k);
                updata(1,n,1,l,r,k);
            } else {
                scanf("%d%d%*c",&l,&r);
                printf("%lld\n",query(1,n,1,l,r));
            }
        }
    }
	return 0;
}


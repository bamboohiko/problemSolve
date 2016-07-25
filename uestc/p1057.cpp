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
LL t[400100],lazy[400100];
void down(int l,int r,int k) {
    int mid = (l + r) >> 1;
    lazy[k<<1] += lazy[k];t[k<<1] += (mid-l+1)*lazy[k];
    lazy[(k<<1)|1] += lazy[k];t[(k<<1)|1] += (r-mid)*lazy[k];
    lazy[k] = 0;
}
void build(int l,int r,int k) {
    if (l == r) {
        lazy[k] = 0;
        scanf("%lld",&t[k]);
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,k<<1);
    build(mid+1,r,(k<<1)|1);
    t[k] = t[k<<1] + t[(k<<1)|1];
}
void updata(int l,int r,int k,int x,int y,LL val) {
    //printf("%d %d %d\n",l,r,k);
    if (x <= l && r <= y) {
        lazy[k] += val;
        t[k] += (r-l+1)*val;
        return;
    }
    if (lazy[k]) down(l,r,k);
    int mid = (l+r) >> 1;
    if (x <= mid) updata(l,mid,k<<1,x,y,val);
    if (y > mid) updata(mid+1,r,(k<<1)|1,x,y,val);
    t[k] = t[k<<1] + t[(k<<1)|1];
}
LL query(int l,int r,int k,int x,int y) {
    //printf("%d %d %d\n",l,r,t[k]);
    if (x <= l && r <= y) {
        return t[k];
    }
    if (lazy[k]) down(l,r,k);
    int mid = (l + r) >> 1;LL s1 = 0,s2 = 0;
    if (x <= mid) s1 = query(l,mid,k<<1,x,y);
    if (y > mid) s2 = query(mid+1,r,(k<<1)|1,x,y);
    return s1+s2;
}
int main() {
    int n,m;
    int l,r;LL v;
    while (scanf("%d",&n) != EOF) {
        build(1,n,1);
        scanf("%d",&m);
        for (int i = 1;i <= m; i++) {
            scanf("%d%d%lld",&l,&r,&v);
            updata(1,n,1,l,r,v);
            printf("%lld\n",query(1,n,1,l,r));
        }
    }
	return 0;
}

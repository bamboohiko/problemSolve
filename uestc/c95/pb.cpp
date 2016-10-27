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
const int maxn = 4e5 + 100;
struct point{
    int op,x,y;
};
point rec[maxn];
int lazy[400100],t[400100],V[400100];
void down(int l,int mid,int r,int k) {
    if (lazy[k]) {
        t[k<<1] = lazy[k<<1] = V[mid+1]-V[l];
        t[k<<1|1] = lazy[k<<1|1] = V[r+1]-V[mid+1];
        lazy[k] = 0;
    }
}
void updata(int l,int r,int k,int x,int y) {
    if (x <= l && r <= y) {
        t[k] = lazy[k] = V[r+1]-V[l];
        return;
    }
    int mid = (l + r) >> 1;
    down(l,mid,r,k);
    if (x <= mid) updata(l,mid,k<<1,x,y);
    if (y > mid) updata(mid+1,r,k<<1|1,x,y);
    t[k] = t[k<<1] + t[k<<1|1];
}
int query(int l,int r,int k,int x,int y) {
    if (x <= l && r <= y) return t[k];
    int mid = (l + r) >> 1,ans = 0;
    down(l,mid,r,k);
    if (x <= mid) ans += query(l,mid,k<<1,x,y);
    if (y > mid) ans += query(mid+1,r,k<<1|1,x,y);
    return ans;
}
int main() {
    int n,q,cnt = 0;
    scanf("%d%d",&n,&q);
    for (int i = 0;i < q; i++) {
        scanf("%d%d%d",&rec[i].op,&rec[i].x,&rec[i].y);
        V[++cnt] = rec[i].x;V[++cnt] = rec[i].y;V[++cnt] = rec[i].y+1;
    }
    sort(V+1,V+cnt+1);
    int m = unique(V+1,V+cnt+1) - V;
    for (int i = 0;i < q; i++) {
        int x = lower_bound(V+1,V+m,rec[i].x) - V,
            y = lower_bound(V+1,V+m,rec[i].y) - V,
            num = rec[i].y-rec[i].x+1;
        if (rec[i].op == 1) updata(1,m-2,1,x,y);
        else printf("%d\n",num - query(1,m-2,1,x,y));
    }
	return 0;
}


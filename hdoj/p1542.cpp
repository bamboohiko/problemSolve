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
    double x1,x2,h;int rec;
    bool operator <(const line& rhs) const {
        return h < rhs.h;
    }
};
struct node{
    int l,r,val;double len;
};
double V[4100];
vector<line> E;
int val[40100];
node a[40100];
void build(int l,int r,int k) {
    a[k].l = l;a[k].r = r;
    if (l+1 >= r) return;
    int mid = (l + r) >> 1;
    build(l,mid,k<<1);
    build(mid,r,k<<1|1);
}
void updata(int l,int r,int k,int op) {
    if (l <= a[k].l && a[k].r <= r) {
        val[k] += op;
    } else {
        int mid = (a[k].l + a[k].r) >> 1;
        if (l < mid) updata(l,r,k<<1,op);
        if (r > mid) updata(l,r,k<<1|1,op);
    }
    if (val[k]) a[k].len = V[a[k].r] - V[a[k].l];
    else a[k].len = a[k<<1].len + a[k<<1|1].len;
    if (l <= a[k].l && a[k].r <= r) return;
}
int main() {
    int n,T = 0;
    while (scanf("%d",&n) != EOF) {
        if (n == 0) break;
        E.clear();
        memset(a,0,sizeof(a));
        memset(val,0,sizeof(val));
        int cnt = 0;
        double x1,x2,y1,y2;
        for (int i = 1;i <= n; i++) {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            E.push_back((line){x1,x2,y1,1});
            E.push_back((line){x1,x2,y2,-1});
            V[++cnt] = x1;V[++cnt] = x2;
        }
        sort(V+1,V+cnt+1);
        int m = unique(V+1,V+cnt+1) - V;
        build(1,m-1,1);
        sort(E.begin(),E.end());
        double ans = 0;
        for (int i = 0;i < (n << 1); i++) {
            int x1 = lower_bound(V+1,V+m,E[i].x1-eps) - V;
            int x2 = lower_bound(V+1,V+m,E[i].x2-eps) - V;
            updata(x1,x2,1,E[i].rec);
            ans += (E[i+1].h-E[i].h)*a[1].len;
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",++T,ans);
    }
	return 0;
}

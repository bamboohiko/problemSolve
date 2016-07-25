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
using namespace std;
typedef long long LL;
const LL inf = 1e12 + 7;
const int maxn = 1e5 + 10;
LL f[maxn],tree[maxn << 2];
LL a[110],b[110],t[110],d;
int n,m;
void build(int l,int r,int k) {
    if (l == r) {
        tree[k] = f[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(l,mid,k<<1);
    build(mid+1,r,k<<1|1);
    tree[k] = max(tree[k<<1],tree[k<<1|1]);
}
void updata(int l,int r,int k,int x,int val) {
    if (l == r) {
        tree[k] = val;
        return;
    }
    int mid = (l+r) >> 1;
    if (x <= mid) updata(l,mid,k<<1,x,val);
    else updata(mid+1,r,k<<1|1,x,val);
    tree[k] = max(tree[k<<1],tree[k<<1|1]);
}
LL query(int l,int r,int k,int x,int y) {
    if (x <= l && r <= y)
        return tree[k];
    int mid = (l+r) >> 1;
    LL d1 = -inf,d2 = -inf;
    if (x <= mid) d1 = query(l,mid,k<<1,x,y);
    if (y > mid) d2 = query(mid+1,r,k<<1|1,x,y);
    return max(d1,d2);
}
LL move(int k,int d) {
    int l = max(1,k-d),r = min(n,k+d);
    LL ans = query(1,n,1,l,r);
    //printf("%d %d %d\n",l,r,ans);
    return ans;
}
int main() {
    scanf("%d%d%lld",&n,&m,&d);
    for (int i = 1;i <= m; i++)
        scanf("%d%d%d",&a[i],&b[i],&t[i]);
    for (int i = 1;i <= n; i++)
        f[i] = b[1] - abs(i - a[1]);
    build(1,n,1);
    for (int j = 2;j <= m; j++) {
        for (int i = 1;i <= n; i++) {
            f[i] = move(i,(t[j]-t[j-1])*d) + b[j] - abs(i-a[j]);
        }
        build(1,n,1);
    }
    LL ans = f[1];
    for (int i = 2;i <= n; i++)
        ans = max(ans,f[i]);
    printf("%lld\n",ans);
	return 0;
}


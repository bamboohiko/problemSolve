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
const int MAXN = 1e5 + 100;
const int inf = 1e9 + 7;
struct leaf{
    int x,y;
};
int a[MAXN],Q[MAXN];
leaf tree[4*MAXN];
void fig(int p) {
    tree[p].x = max(tree[p+p].x,tree[p+p+1].x);
    tree[p].y = min(tree[p+p].y,tree[p+p+1].y);
}
void build(int p,int l,int r) {
    if (l == r) {
        tree[p].x = tree[p].y = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p+p,l,mid);
    build(p+p+1,mid+1,r);
    fig(p);
}
int queryx(int p,int l,int r,int x,int y) {
    if (x <= l && r <= y)
        return tree[p].x;
    int mid = (l + r) >> 1,k1 = 0,k2 = 0;
    if (x <= mid) k1 = queryx(p+p,l,mid,x,y);
    if (y > mid) k2 = queryx(p+p+1,mid+1,r,x,y);
    return max(k1,k2);
}
int  queryy(int p,int l,int r,int x,int y) {
    if (x <= l && r <= y)
        return tree[p].y;
    int mid = (l + r) >> 1,k1 = inf,k2 = inf;
    if (x <= mid) k1 = queryy(p+p,l,mid,x,y);
    if (y > mid) k2 = queryy(p+p+1,mid+1,r,x,y);
    return min(k1,k2);
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,k;
        scanf("%d%d",&n,&k);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        build(1,1,n);
        int fr = 1,ed = 2;
        long long ans = 0;
        Q[1] = a[1];
        for (int i = 2;i <= n; i++) {
            while (fr < ed && (abs(queryx(1,1,n,fr,ed-1) - a[i]) >= k || abs(queryy(1,1,n,fr,ed-1) - a[i]) >= k)) {
                ans += ed - fr;
                fr++;
            }
            Q[ed++] = a[i];
        }
        int sum = ed - fr;
        ans += (sum+1)*sum/2;
        printf("%lld\n",ans);
    }
	return 0;
}

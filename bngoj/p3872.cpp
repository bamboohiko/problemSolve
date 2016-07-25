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
const int maxn = 500 + 10;
int t[4*maxn],lazy[4*maxn];
void build(int l,int r,int k) {
    if (l == r) {
        t[l] = lazy[l] = 0;
        return;
    }
    int mid =(l + r) >> 1;
    build(l,mid,k << 1);
    build(mid+1,r,k << 1|1);
    t[k] = 0;
}
int down(int k,int l,int r) {
    int mid = (l+r) >> 1;
	if (lazy[k]) {
		lazy[k << 1] ^= lazy[k];
		t[k << 1] = (mid-l+1) - t[k << 1];
		lazy[k << 1|1] ^= lazy[k];
		t[k << 1|1] = (r-mid) - t[k << 1|1];
		lazy[k] = 0;
	}
}
int query(int l,int r,int k,int x,int y) {
    if (x <= l && r <= y)
		return t[k];
	down(k,l,r);
	int mid = (l+r) >> 1, ans = 0;
	if (x <= mid) ans += query(l,mid,k+k,x,y);
	if (y > mid) ans += query(mid+1,r,k+k+1,x,y);
	return ans;
}
int updata(int l,int r,int k,int x,int y) {
    if (x <= l && r <= y) {
		lazy[k] ^= 1;
		return t[k] = (r-l+1) - t[k];
	}
	int mid = (l + r) >> 1;
	down(k,l,r);
	if (x <= mid) updata(l,mid,k+k,x,y);
	if (y > mid) updata(mid+1,r,k+k+1,x,y);
	t[k] = t[k << 1] + t[k << 1|1];
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,n,1);
    int opt,l,r;
    for (int i = 1;i <= m; i++) {
        scanf("%d%d%d",&opt,&l,&r);
        if (opt == 0) updata(1,n,1,l,r);
        else printf("%d\n",query(1,n,1,l,r));
    }
	return 0;
}


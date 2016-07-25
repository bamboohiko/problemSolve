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
const int maxn = 1e5;
LL a[3*maxn + 100];
void updata(int l,int r,int k,int x,int y) {
    if (l == r) {
        a[k] += y;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) updata(l,mid,k<<1,x,y);
    else updata(mid+1,r,k<<1|1,x,y);
    a[k] = max(a[k<<1],a[k<<1|1]);
}
LL query(int l,int r,int k,int x,int y) {
    if (x <= l && r <= y) return a[k];
    int mid = (l + r) >> 1;LL r1 = 0,r2 = 0;
    if (x <= mid) r1 = query(l,mid,k<<1,x,y);
    if (y > mid) r2 = query(mid+1,r,k<<1|1,x,y);
    return max(r1,r2);
}
int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    int op,x,y;
    for (int i = 1;i <= q; i++) {
        scanf("%d%d%d",&op,&x,&y);
        if (op == 1) updata(1,n,1,x,y);
        else printf("%lld\n",query(1,n,1,x,y));
    }
	return 0;
}


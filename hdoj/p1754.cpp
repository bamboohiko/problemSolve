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
const int maxn = 2e5 + 10;
int t[maxn*4],n,m;
void build(int l,int r,int k) {
    if (l == r) {
        scanf("%d",&t[k]);
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,k<<1);
    build(mid+1,r,(k<<1)|1);
    t[k] = max(t[k<<1],t[(k<<1)|1]);
}
void updata(int l,int r,int k,int x,int val) {
    if (l == r) {
        t[k] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) updata(l,mid,k<<1,x,val);
    else updata(mid+1,r,(k<<1)|1,x,val);
    t[k] = max(t[k<<1],t[(k<<1)|1]);
}
int query(int l,int r,int k,int x,int y) {
    if (x <= l && r <= y) {
        return t[k];
    }
    int mid = (l + r) >> 1,s1 = 0,s2 = 0;
    if (x <= mid) s1 = query(l,mid,k<<1,x,y);
    if (y > mid) s2 = query(mid+1,r,(k<<1)|1,x,y);
    return max(s1,s2);
}
int main() {
    int l,r;char ch;
    while (scanf("%d%d",&n,&m) != EOF) {
        memset(t,0,sizeof(t));
        build(1,n,1);
        getchar();
        for (int i = 1;i <= m; i++) {
            scanf("%c%d%d%*c",&ch,&l,&r);
            if (ch == 'U') updata(1,n,1,l,r);
            else printf("%d\n",query(1,n,1,l,r));
        }
    }
	return 0;
}


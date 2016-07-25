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
struct bit{
    LL a,b;
    bit(LL _a = 0,LL _b = 0) {
        a = _a;b = _b;
    }
    void set1(int k) {
        a = b = 0;
        if (k >= 60) a = (LL)1 << (k-60);
        else b = (LL)1 << k;
    }
    bit operator |(bit rhs) {
        return bit(a|rhs.a,b|rhs.b);
    }
    int cnt(int m) {
        int ans = 0;
        for (int i = 1;i < min(60,m+1); i++)
            if (b&((LL)1 << i)) ans++;
        for (int i = 60;i <= m;i++)
            if (a&((LL)1 << (i-60))) ans++;
        return ans;
    }
};
bit t[maxn],lazy[maxn];
void down(int l,int mid,int r,int k) {
    if (lazy[k].a || lazy[k].b) {
        lazy[k<<1] = t[k<<1] = lazy[k];
        lazy[k<<1|1] = t[k<<1|1] = lazy[k];
        lazy[k].a = lazy[k].b = 0;
    }
}
void build(int l,int r,int k) {
    if (l == r) {
        int loc;scanf("%d",&loc);
        t[k].set1(loc);
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,k<<1);
    build(mid+1,r,k<<1|1);
    t[k] = t[k<<1]|t[k<<1|1];
}
void updata(int l,int r,int k,int x,int y,int val) {
    if (x <= l && r <= y) {
        lazy[k].set1(val);t[k].set1(val);
        return;
    }
    int mid = (l + r) >> 1;
    down(l,mid,r,k);
    if (x <= mid) updata(l,mid,k<<1,x,y,val);
    if (y > mid) updata(mid+1,r,k<<1|1,x,y,val);
    t[k] = t[k<<1]|t[k<<1|1];
}
bit query(int l,int r,int k,int x,int y) {
    //cout << l << " " << r << endl;
    if (x <= l && r <= y) return t[k];
    int mid = (l + r) >> 1;
    bit ans;
    down(l,mid,r,k);
    if (x <= mid) ans = ans|query(l,mid,k<<1,x,y);
    if (y > mid) ans = ans|query(mid+1,r,k<<1|1,x,y);
    return ans;
}
int main() {
    int n,m,q;char ch;
    int x,y,val;
    scanf("%d%d",&n,&m);
    build(1,n,1);
    scanf("%d",&q);
    while (q--) {
        getchar();ch = getchar();
        if (ch == 'Q') {
            scanf("%d%d",&x,&y);
            bit b = query(1,n,1,x,y);
            printf("%d\n",b.cnt(m));
        } else {
            scanf("%d%d%d",&x,&y,&val);
            updata(1,n,1,x,y,val);
        }
    }
	return 0;
}


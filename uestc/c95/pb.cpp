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
const int maxn = 2e5 + 100;
struct point{
    int op,x,y;
};
point rec[maxn];
map<int,int> D;
vector<int> V;
void down(int l,int mid,int r,int k) {
    if (lazy[k]) {
        t[k<<1] = lazy[k<<1] = mid-l+1;
        t[k<<1|1] = lazy[k<<1|1] = r-mid;
        lazy[k] = 0;
    }
}
void updata(int l,int r,int k,int x,int y) {
    if (x <= l && r <= y) {
        t[k] = lazy[k] = r-l+1;
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
    t[k] = t[k<<1] + t[k<<1|1];
}
int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i = 0;i < q; i++) {
        scanf("%d%d%d",&rec[i].op,&rec[i].x,&rec[i].y);
        if (!D.count(rec[i].x)) {D[rec[i].x] = 1;V.push_back(rec[i].x);}
        if (!D.count(rec[i].y)) {D[rec[i].y] = 1;V.push_back(rec[i].y);}
    }

	return 0;
}


#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
typedef long long LL;
using namespace std;
#define INF 0x3FFFFFFF;
const double eps = 1e-8;
const int maxn = 1e5 + 10;
int t[4*maxn],a[maxn];
string st;
void build(int l,int r,int k) {
    if (l == r) {
        t[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,k<<1);
    build(mid+1,r,(k<<1)|1);
    t[k] = max(t[k<<1],t[(k<<1)|1]);
}
int query(int l,int r,int k,int x) {
    //cout << l << " " << r << " " <<t[k] << " " << x << endl;
    if (t[k] < x) return -1;
    if (l == r) {
        t[k] = 0;
        return l;
    }
    int mid = (l + r) >> 1,ans;
    if (t[k<<1] < x) ans = query(mid+1,r,(k<<1)|1,x);
    else if (t[k<<1|1] < x) ans = query(l,mid,k<<1,x);
    else if (t[k<<1] <= t[(k<<1)|1]) ans = query(l,mid,k<<1,x);
    else ans = query(mid+1,r,(k<<1)|1,x);
    t[k] = max(t[k<<1],t[(k<<1)|1]);
    return ans;
}
void add(int l,int r,int k,int x) {
    if (l == r) {
        t[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) add(l,mid,k<<1,x);
    else add(mid+1,r,(k<<1)|1,x);
    t[k] = max(t[k<<1],t[(k<<1)|1]);
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    build(1,n,1);
    int x;
    for (int i = 1;i <= m; i++) {
        cin >> st >> x;
        if (st[0] == 'i') printf("%d\n",query(1,n,1,x));
        else add(1,n,1,x);
    }
    return 0;
}

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
struct point {
    int l,r,num;
    bool operator <(const point &rhs) const {
        return r < rhs.r;
    }
};
point a[maxn];
int f[maxn],ans[maxn];
int t[maxn],n;
bool cmp(int x,int y) {
    return a[x].l > a[y].l;
}
void ins(int k,int add) {
    for (int i = k;i <= n;i += i&(-i))
        t[i] += add;
}
int sum(int k) {
    int ans = 0;
    for (int i = k;i > 0;i -= i&(-i))
        ans += t[i];
    return ans;
}
int main() {
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d%d",&a[i].l,&a[i].r);a[i].num = i;
        f[i] = i;
    }
    sort(a+1,a+n+1);
    sort(f+1,f+n+1,cmp);
    for (int i = 1;i <= n; i++) {
        ins(f[i],1);
        ans[a[f[i]].num] = sum(f[i]-1);
    }
    for (int i = 1;i <= n; i++) printf("%d\n",ans[i]);
	return 0;
}

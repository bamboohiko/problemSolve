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
const int maxn = 1e5 + 100;
const int inf = 1e9 + 10;
struct point{
    int m,s;
};
point a[maxn];
int m[maxn],s[maxn];
long long sum[maxn];
bool cmp(point a,point b) {
    return a.m < b.m;
}
int main() {
    int n,d;
    scanf("%d%d",&n,&d);
    for (int i = 1;i <= n; i++) scanf("%d%d",&a[i].m,&a[i].s);
    sort(a+1,a+n+1,cmp);
    for (int i = 1;i <= n; i++) {
        m[i] = a[i].m;
        s[i] = a[i].s;
    }
    memset(sum,0,sizeof(sum));
    for (int i = 1;i <= n; i++) sum[i] = sum[i-1] + s[i];
    long long ans = 0;
    for (int i = 1;i <= n; i++) {
        int r = upper_bound(m+1,m+n+1,m[i]+d-1) - m;
        ans = max(ans,sum[r-1]- sum[i-1]);
    }
    printf("%I64d\n",ans);
	return 0;
}

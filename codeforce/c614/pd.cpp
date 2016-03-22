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
const int maxn = 1e5 + 10;
int a[maxn],ind[maxn];
LL sum[maxn],A,m;
int biser(int m,int n) {
    int l = 0,r = A,ans = 0;
    while (l < r) {
        int mid = l + (r-l) >> 1;
        int p = lower_bound(b+1,b+n,mid) - a;
        if (p*mid - sum[p] <= m)
    }
}
int main() {
    int n,cf,cm;
    scanf("%d%I64d%d%d%I64d",&n,&A,&cf,&cm,&m);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        ind[i] = i;
    }
    sort(ind+1,ind+n+1,cmp);
    for (int i = 1;i <= n; i++) b[i] = a[ind[i]];
    int p = n,ans1 = 0,ans 2 = n;
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + b[i]];
    l = biser(m,n+1);r = n+1;ans = l*cm + (n-r+1)*cf;
    for (int i = n; i >= 1; i--) {
        m -= A - b[i];
        if (m >= 0) {
            int nl = biser(m,i);
            if (nl*cm + (n-i+1)*cf > ans) {
                l = nl;r = i;
                ans = l*cm + (n-r+1)*cf;
            }
        }
    }
    for (int i = 1;i <= n; i++) {
        if (i >= r) a[ind[i]] = A;
        else if (b[i] < l) a[ind[i]] = l;
    }
    printf("%d\n",ans);
    for (int i = 1;i < n; i++) printf("%d ",a[i]);
    printf("%d\n",a[n]);
	return 0;
}


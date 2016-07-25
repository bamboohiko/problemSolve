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
const int maxn = 2e6 + 100;
int q[maxn],a[maxn],sum[maxn];
bool cmp(int a,int b,int c,int _a,int _b,int _c) {
    if (a != _a) return a > _a;
    if (b != _b) return b < _b;
    return c < _c;
}
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int ans = -1001,x,y;
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        a[n+i] = a[i];
        if (a[i] > ans) {ans = a[i];x = y = i;}
    }
    int l = 1,r = 1;q[1] = 0;
    for (int i = 1;i <= n+n; i++) {
        sum[i] = sum[i-1] + a[i];
        while (l <= r && i-q[l] > k) {
            if (q[r] > q[l] && cmp(sum[q[r]] - sum[q[l]],q[l]+1,q[r]-q[l],ans,x,y-x+1)) {
                ans = sum[q[r]] - sum[q[l]];
                x = q[l] + 1;y = q[r];
            }
            l++;
        }
        while (l <= r && sum[i] < sum[q[r]]) r--;
        q[++r] = i;
        if (q[r] > q[l] && cmp(sum[q[r]] - sum[q[l]],q[l]+1,q[r]-q[l],ans,x,y-x+1)) {
            ans = sum[q[r]] - sum[q[l]];
            x = q[l] + 1;y = q[r];
        }
    }
    if (q[r] > q[l] && sum[q[r]]-sum[q[l]] > ans) {
        ans = sum[q[r]] - sum[q[l]];
        x = q[l]+1,y = q[r];
    }
    printf("%d %d %d\n",ans,x,(y-1)%n+1);
	return 0;
}

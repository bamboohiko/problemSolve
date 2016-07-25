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
const int maxn = 1e5 + 10;
int a[maxn],t1[maxn],t2[maxn];
int n,m;
int query(int* t,int k) {
    int ans = 0;
    for ( ;k > 0; k -= k&(-k)) ans += t[k];
    return ans;
}
void updata(int* t,int k,int d) {
    for ( ;k <= n; k += k&(-k)) t[k] += d;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(t1,0,sizeof(t1));
        memset(t2,0,sizeof(t2));
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        long long now = 0;
        for (int i = n;i > m; i--) {
            now += query(t2,a[i]-1);
            updata(t2,a[i],1);
        }
        long long ans = now;
        for (int i = 1;i + m <= n; i++) {
            now += query(t1,n) - query(t1,a[i]) + query(t2,a[i]-1);
            updata(t1,a[i],1);
            //printf("%d %d %d\n",query(t1,n),query(t1,a[i+m]),query(t2,a[i+m]));
            now -= query(t1,n) - query(t1,a[i+m]) + query(t2,a[i+m]-1);
            updata(t2,a[i+m],-1);
            ans = min(ans,now);
        }
        printf("%lld\n",ans);
    }
	return 0;
}


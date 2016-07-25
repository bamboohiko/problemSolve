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
const int maxn = 1e6 + 100;
const LL mod = 772002+233 ;
LL tval[maxn],tcnt[maxn],a[maxn];
void add(LL a[],int n,int k,int x) {
    for (int i = k;i <= n; i += i&(-i))
        a[i] = (a[i] + x)%mod;
}
LL sum(LL a[],int k) {
    LL ans = 0;
    for (int i = k;i >= 1;i -= i&(-i))
        ans = (ans + a[i])%mod;
    return ans;
}
int main() {
    int n,q;
    int op,x,y;
    scanf("%d%d",&n,&q);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    while (q--) {
        scanf("%d",&op);
        if (op == 1) {
            scanf("%d%d",&x,&y);
            add(tval,n,x,x+y);
            add(tval,n,x+y,-(x+y));
            add(tcnt,n,x,1);
            add(tcnt,n,x+y,-1);
        } else {
            scanf("%d",&x);
            printf("%lld\n",((a[x]+sum(tval,x)-sum(tcnt,x)*x)%mod + mod)%mod);
        }
    }
	return 0;
}


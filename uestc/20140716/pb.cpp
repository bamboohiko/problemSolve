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
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m,&d);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&u[i]);
            v[i] = -(u[i] + d);
        }
        for (int i = 1;i <= m; i++) {
            scanf("%d",&b[i]);
            int op = lower_bound(v+1,v+n+1,b[i]) - v;
            int ed = lower_bound(u+1,u+n+1,-(b[i]+d)) - u;
            if (op <= ed) rec[op] = 1;rec[ed] = -1;
        }

    }
	return 0;
}

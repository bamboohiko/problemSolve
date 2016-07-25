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
    int n,m,q;
    int x,y,k;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) {f[i] = i;dis[i] = 0;}
    for (int i = 1;i <= m; i++) {
        scanf("%d%d%d",&a[i],b[i],c[i]);
        getchar();getchar();
    }
    scanf("%d",&q);
    j = 1;
    for (int i = 1;i <= q; i++) {
        scanf("%d%d",&x,&y,&k);
        for (;j <= k; j++) {
            int x = find(a[i]).y = find(b[i]);
            f[]
        }
    }
	return 0;
}


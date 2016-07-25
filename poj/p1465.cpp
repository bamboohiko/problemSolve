//搜索
//bfs，从大到小确定每一位，用剩余类进行剪枝
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
struct point {
    int v,num,f;
};
point Q[1001000];
bool vis[5010];
int a[20],top = 0;
void dfs(int k) {
    if (Q[k].f) dfs(Q[k].f);
    printf("%d",Q[k].num);
}
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        memset(vis,0,sizeof(vis));
        for (int i = 0; i < m; i++) scanf("%d",&a[i]);
        sort(a,a+m);
        int p1 = 0,p2 = 1,ans = 0;
        if (n != 0 ) {
            while (p1 < p2) {
                point& s = Q[p1];
                for (int i = 0; i < m; i++) {
                    if (s.v == 0 && a[i] == 0) continue;
                    point t;
                    t.v = (s.v*10 + a[i])%n;t.num = a[i];t.f = p1;
                    if (vis[t.v]) continue;
                    else vis[t.v] = true;
                    Q[p2++] = t;
                    if (t.v == 0) {
                        ans = p2-1;
                        break;
                    }
                }
                if (ans > 0) break;
                p1++;
            }
        }
        if (ans > 0) {
            dfs(ans);
            printf("\n");
        } else puts("0");
    }
    return 0;
}

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
priority_queue<int,vector<int>,greater<int> > Q;
const int maxn = 1e5 + 10;
int next[maxn],vis[maxn],loc[maxn];
int a[maxn],d[maxn];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    memset(next,-1,sizeof(next));
    for (int i = 1;i <= n; i++) {
        scanf("%d",&d[i]);
        if (d[i]) {
            next[loc[d[i]]] = i;
            loc[d[i]] = i;
        }
    }
    for (int i = 1;i <= m; i++) scanf("%d",&a[i]);
    int use = 0,del = m,ans = -1;
    for (int i = 1;i <= n; i++)
        if (d[i]) {
            if (!vis[d[i]]) {
                while (!Q.empty() && i-1-use < a[d[i]]) {
                        int p = Q.top();Q.pop();
                        if (p > 0 && vis[d[p]] == p) {
                            vis[d[p]] = 0;
                            use -= a[d[p]] + 1;
                            del++;
                        }
                }
                if (i-1-use >= a[d[i]]) {
                    vis[d[i]] = next[i];
                    use += a[d[i]] + 1;
                    Q.push(next[i]);
                    del--;
                    if (del == 0) {
                        ans = i;
                        break;
                    }
                }
            } else {
                vis[d[i]] = next[i];
                Q.push(next[i]);
            }
        }
    printf("%d\n",ans);
	return 0;
}

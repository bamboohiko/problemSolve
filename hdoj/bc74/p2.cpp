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
const int maxn = 3e5;
const LL mod = 1e9 + 7;
struct point {
    int k,step;
};
queue<point> Q;
int a[40],dis[maxn + 100];
int main() {
    int t,n,m;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n; i++) scanf("%d",&a[20+i]);
        for (int i = 0;i <= 20; i++) a[i] = 1 << i;
        n += 20;
        memset(dis,INF,sizeof(dis));dis[0] = 0;
        Q.push((point){0,0});
        while (!Q.empty()) {
            point s = Q.front();Q.pop();
            for (int i = 0;i <= n; i++) {
                int t = s.k^a[i];
                if (t <= maxn && dis[t] == INF) {
                    dis[t] = s.step + 1;
                    Q.push((point){t,dis[t]});
                }
            }
        }
        //for (int i = 1;i <= maxn; i++)
        //    if (dis[i] == INF) cout << "!";
        int x,y;
        LL ans = 0;
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&x,&y);
            //cout << dis[x^y] << endl;
            ans = (ans + (LL)dis[x^y]*i)%mod;
        }
        printf("%lld\n",ans);
    }
	return 0;
}


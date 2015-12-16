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
struct Edge {
    int to,next;
    double r,c;
};
struct Node {
    int p,cnt;
};
Edge edge[210];
int head[110];
double dis[110];
bool vis[110];
int n,m,s,cnt;
double v;
void build(int from,int to,double r,double c) {
    edge[++cnt].to = to;
    edge[cnt].r = r;
    edge[cnt].c = c;
    edge[cnt].next = head[from];
    head[from] = cnt;
}
bool spfa() {
    for (int i = 1; i <= n; i++) dis[i] = 0;
    dis[s] = v;
    queue<Node> Q;
    memset(vis,0,sizeof(vis));
    Q.push((Node) {
        s,0
    });
    vis[s] = true;
    while (!Q.empty()) {
        Node s = Q.front();
        Q.pop();
        if (s.cnt > n) return true;
        for (int i = head[s.p]; i ; i = edge[i].next) {
            Edge t = edge[i];
            if (vis[t.to]) continue;
            double ans = (dis[s.p] - t.c)*t.r;
            //cout << ans << endl;
            if (ans > dis[t.to]) {
                vis[t.to] = true;
                dis[t.to] = ans;
                Q.push((Node) {
                    t.to,s.cnt+1
                });
            }
        }
        vis[s.p] = false;
    }
    return false;
}
int main() {
    while (scanf("%d%d%d%lf",&n,&m,&s,&v) != EOF) {
        int from,to;
        double r,c;
        cnt = 0;
        memset(head,0,sizeof(head));
        for (int i = 1; i <= m; i++) {
            scanf("%d%d",&from,&to);
            scanf("%lf%lf",&r,&c);
            build(from,to,r,c);
            scanf("%lf%lf",&r,&c);
            build(to,from,r,c);
        }
        if (spfa()) puts("YES");
        else puts("NO");
        //for (int i = 1;i <= n; i++) cout << dis[i] << " ";cout << endl;
    }
    return 0;
}

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
struct Edge {
    int to,next,dis;
};
struct point {
    int to,dis;
    point(int x = 0,int y = 0) {
        to = x;dis = y;
    }
    bool operator <(const point &rhs) const {
        return dis > rhs.dis;
    }
};
Edge edge[10100];
int head[110],cou = 0;
int dis[110],lev[110];
priority_queue<point> Q;
void build(int from,int to,int dis) {
    edge[++cou].to = to;edge[cou].dis = dis;
    edge[cou].next = head[from];head[from] = cou;
}
int spfa(int l,int r) {
    memset(dis,INF,sizeof(dis));dis[0] = 0;
    Q.push(point(0,0));
    while (!Q.empty()) {
        point s = Q.top();Q.pop();
        if (s.dis > dis[s.to]) continue;
        for (int i = head[s.to];i != -1;i = edge[i].next) {
            int t = edge[i].to;
            if (lev[t] >= l && lev[t] <= r && dis[t] > dis[s.to] + edge[i].dis) {
                dis[t] = dis[s.to] + edge[i].dis;
                //cout << t << " " << dis[t] << endl;
                Q.push(point(t,dis[t]));
            }
        }
    }
    return dis[1];
}
int main() {
    int n,m;
    int x,from,to,dist;
    while (scanf("%d%d",&m,&n) != EOF) {
        memset(head,-1,sizeof(head));cou = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d",&dist,&lev[i],&x);
            build(0,i,dist);
            while (x--) {
                scanf("%d%d",&from,&dist);
                build(from,i,dist);
            }
        }
        int ans = INF;
        for (int drt = lev[1]-m;drt <= lev[1]; drt++) {
            int rec = spfa(drt,drt+m);
            //cout << rec << endl;
            ans = min(ans,rec);
        }
        printf("%d\n",ans);
    }
    return 0;
}


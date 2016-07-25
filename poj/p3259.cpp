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
struct point{
    int to,dis;
    point(int x = 0,int y = 0) {
        to = x;dis = y;
    }
    bool operator <(const point &rhs) const {
        return dis < rhs.dis;
    }
};
Edge edge[101000];
int head[1010],dis[1010],cou = 0;
priority_queue<point> Q;
void build(int from,int to,int dis) {
    edge[++cou].to = to;edge[cou].dis = dis;
    edge[cou].next = head[from];head[from] = cou;
}
int spfa() {
    memset(dis,INF,sizeof(dis));dis[1] = 0;
    Q.push(point(1,0));
    while (!Q.empty()) {
        point s = Q.top();Q.pop();
        if (s.dis > dis[s.to]) continue;
        if (dis[1] < 0) return true;
        for (int i = head[s.to];i ; i = edge[i].next) {
            int t = edge[i].to;
            if (dis[t] > dis[s.to] + edge[i].dis) {
                dis[t] = dis[s.to] + edge[i].dis;
                Q.push(point(t,dis[t]));
            }
        }
    }
    return false;
}
int main() {
    int t;
    int n,m,w;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d",&n,&m,&w);
        int from,to,dis;cou = 0;
        memset(head,0,sizeof(head));
        for (int i = 1;i <= m; i++) {
            scanf("%d%d%d",&from,&to,&dis);
            build(from,to,dis);
            build(to,from,dis);
        }
        for (int i = 1;i <= w; i++) {
            scanf("%d%d%d",&from,&to,&dis);
            build(from,to,-dis);
        }
        if (spfa()) puts("YES");
        else puts("NO");
    }
	return 0;
}


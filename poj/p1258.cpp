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
    int to,dis;
    point(int _x = 0,int _y = 0) {
        to = _x;dis = _y;
    }
    bool operator <(const point &rhs) const {
        return dis > rhs.dis;
    }
};
priority_queue<point> Q;
bool vis[110];
int dis[110],a[110][110];
int prim(int n) {
    int ans = 0;
    memset(dis,INF,sizeof(dis));dis[1] = 0;
    memset(vis,0,sizeof(vis));
    Q.push(point(1,0));
    while (!Q.empty()) {
        point s = Q.top();Q.pop();
        if (vis[s.to]) continue;
        vis[s.to] = true;
        for (int i = 1;i <= n; i++)
            if (!vis[i] && dis[i] > a[s.to][i]) {
                dis[i] = a[s.to][i];
                Q.push(point(i,dis[i]));
            }
        ans += dis[s.to];
    }
    return ans;
}
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= n; j++)
                scanf("%d",&a[i][j]);
        printf("%d\n",prim(n));
    }
	return 0;
}


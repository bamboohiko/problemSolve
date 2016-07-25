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
struct point{
    int to,dis;
    point(int x = 0,int y = 0) {
        to = x;dis = y;
    }
    bool operator <(const point &rhs) const {
        return dis > rhs.dis;
    }
};
priority_queue<point> Q;
char st[2010][10];
int a[2010][2010],dis[2010];
bool vis[2010];
int prim(int n) {
    int ans = 0;
    for (int i = 1;i <= n; i++) {
        dis[i] = a[1][i];
        Q.push(point(i,dis[i]));
    }
    memset(vis,0,sizeof(vis));
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
    while (scanf("%d%*c",&n) != EOF && n) {
        for (int i = 1;i <= n; i++) gets(st[i]);
        memset(a,0,sizeof(a));
        for (int i = 1;i <= n; i++)
            for (int j = i+1;j <= n; j++) {
                for (int k = 0;k < 7; k++)
                    if (st[i][k] != st[j][k]) a[i][j]++;
                a[j][i] = a[i][j];
            }
        printf("The highest possible quality is 1/%d.\n",prim(n));
    }
	return 0;
}


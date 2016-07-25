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
    double x,y;
};
queue<int> Q;
bool vis[210];
double G[210][210];
point p[210];
double dis(point a,point b) {
    double x = a.x-b.x,y = a.y-b.y;
    return sqrt(x*x+y*y);
}
int main() {
    int n,cou = 0;
    while (scanf("%d",&n) != EOF && n) {
        for (int i = 1;i <= n; i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= n; j++)
                G[j][i] = G[i][j] = dis(p[i],p[j]);
        double l = 0,r = dis(p[1],p[2]);
        while (r - l > eps) {
            double mid = (l+r)/2;
            Q.push(1);
            memset(vis,0,sizeof(vis));vis[1] = true;
            while (!Q.empty()) {
                int s = Q.front();Q.pop();
                for (int t = 1; t <= n; t++)
                    if (!vis[t] && G[s][t] <= mid) {
                        vis[t] = true;
                        Q.push(t);
                    }
                if (vis[2]) break;
            }
            while (!Q.empty()) Q.pop();
            if (vis[2]) r = mid;
            else l = mid;
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",++cou,l);
    }
	return 0;
}


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
const int mov[4][2] = {0,1,-1,0,0,-1,1,0};
int G[110][110],x[110],y[110],p[110];
int main() {
    int t;
    int r,c,n,m;char ch;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d%d",&r,&c,&n,&m);
        memset(G,0,sizeof(G));
        for (int i = 1;i <= n; i++) {
            scanf("%d%d%*c%c",&x[i],&y[i],&ch);
            if (ch == 'N') p[i] = 0;
            else if (ch == 'W') p[i] = 1;
            else if (ch == 'S') p[i] = 2;
            else p[i] = 3;
            G[x[i]][y[i]] = i;
        }
        bool ok = true;
        int w,re;
        while (m--) {
            scanf("%d%*c%c%d",&w,&ch,&re);
            while (re-- && ok) {
                if (ch == 'L') p[w] = (p[w] + 1)%4;
                if (ch == 'R') p[w] = (p[w] + 3)%4;
                if (ch == 'F') {
                    G[x[w]][y[w]] = 0;
                    x[w] += mov[p[w]][0];y[w] += mov[p[w]][1];
                    if (x[w] < 1 || x[w] > r || y[w] < 1 || y[w] > c) {
                        printf("Robot %d crashes into the wall\n",w);
                        ok = false;
                    } else if (G[x[w]][y[w]]) {
                        printf("Robot %d crashes into robot %d\n",w,G[x[w]][y[w]]);
                        ok = false;
                    } else G[x[w]][y[w]] = w;
                    //cout << x[w] << " " << y[w] << endl;
                }
            }
        }
        if (ok) puts("OK");
    }
	return 0;
}


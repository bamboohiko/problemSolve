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
const int move[8][2] = {1,0,-1,0,0,1,0,-1,1,1,-1,-1,1,-1,-1,1};
struct point {
    int x,y;
    point(int _x = 0,int _y = 0):x(_x),y(_y) {}
};
point Q[2000100];
int a[1010][1010];
int n,m;
void bfs(int x,int y) {
    int p1 = 0,p2 = 0;
    point s(x,y);Q[p2++] = s;
    while (p1 < p2) {
        point s = Q[p1++];
        for (int i = 0;i < 8; i++) {
            point t(s.x + move[i][0],s.y + move[i][1]);
            if (t.x <= 0 || t.x > n || t.y <= 0 || t.y > m) continue;
            if (a[t.x][t.y] == 1) continue;
            Q[p2++] = t;
            a[t.x][t.y] = 1;
        }
    }
}
int main() {
    char c;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) {
        getchar();
        for (int j = 1;j <= m; j++) {
            c = getchar();
            if (c == '.') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1;i <= n; i++)
        for (int j = 1;j <= m; j++)
            if (a[i][j] == 0) {
                //printf("%d %d\n",i,j);
                ans++;
                a[i][j] = 1;
                bfs(i,j);
            }
    printf("%d\n",ans);
	return 0;
}


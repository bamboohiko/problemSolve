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
const int mov[8][2] = {1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1};
bool vis[10][10];
int step[5][10][10];

struct point{
    int x,y,step;
    point(int _x = 0,int _y = 0,int _s = 0) {
        x = _x;y = _y;step = _s;
    }
};
queue<point> Q;
void bfs(int k,int x,int y) {
    memset(vis,0,sizeof(vis));
    Q.push(point(x,y,0));
    vis[x][y] = true;
    step[k][x][y] = 0;
    while (!Q.empty()) {
        point s = Q.front();Q.pop();
        for (int i = 0;i < 8; i++) {
            int nx = s.x + mov[i][0],ny = s.y + mov[i][1];
            if (nx < 1 || nx > 8 || ny < 1 || ny > 8 || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            step[k][nx][ny] = s.step + 1;
            Q.push(point(nx,ny,s.step + 1));
        }
    }
}
int main() {
    int t;
    scanf("%d%*c",&t);
    while (t--) {
        int x,y;char ch;
        memset(step,0,sizeof(step));
        for (int i = 1;i <= 3; i++) {
            scanf("%c%d%*c",&ch,&y);
            x = ch - 'A' + 1;
            bfs(i,x,y);
        }
        x = 1,y = 1;
        int ans = step[1][1][1] + step[2][1][1] + step[3][1][1];
        for (int i = 1;i <= 8; i++)
            for (int j = 1;j <= 8; j++) {
                ans = min(ans,step[1][i][j] + step[2][i][j] + step[3][i][j]);
            }
        printf("%d\n",ans);
    }
	return 0;
}

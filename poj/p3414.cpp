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
struct point {
    int x,y,f,act;
};
point line[10100];
bool vis[110][110];
void print(int k,int cnt) {
    if (line[k].f) print(line[k].f,cnt+1);
    else printf("%d\n",cnt);
        if (line[k].act == 1) puts("FILL(1)");
        if (line[k].act == 2) puts("FILL(2)");
        if (line[k].act == 3) puts("DROP(1)");
        if (line[k].act == 4) puts("DROP(2)");
        if (line[k].act == 5) puts("POUR(1,2)");
        if (line[k].act == 6) puts("POUR(2,1)");

}
int main() {
    int a,b,c;
    while (scanf("%d%d%d",&a,&b,&c) != EOF) {
        memset(vis,0,sizeof(vis));
        int p1 = 1,p2 = 1;
        line[p2++] = (point){0,0,0};
        vis[0][0] = true;
        bool ans = false;
        while (p1 < p2) {
            point p = line[p1];
            if (p.x == c || p.y == c) {
                print(p1,0);
                ans = true;
                break;
            }
            if (!vis[a][p.y]) {
                line[p2++] = (point){a,p.y,p1,1};
                vis[a][p.y] = true;
            }
            if (!vis[p.x][b]) {
                line[p2++] = (point){p.x,b,p1,2};
                vis[p.x][b] = true;
            }
            if (!vis[0][p.y]) {
                line[p2++] = (point){0,p.y,p1,3};
                vis[0][p.y] = true;
            }
            if (!vis[p.x][0]) {
                line[p2++] = (point){p.x,0,p1,4};
                vis[p.x][0] = true;
            }
            int x = p.x,y = p.y;
            if (p.x + p.y > b) x = p.x+p.y-b,y = b;
            else x = 0,y = p.x+p.y;
            if (!vis[x][y]) {
                line[p2++] = (point){x,y,p1,5};
                vis[x][y] = true;
            }
            x = p.x,y = p.y;
            if (p.x + p.y > a) x = a,y = p.x+p.y-a;
            else x = p.x+p.y,y = 0;
            if (!vis[x][y]) {
                line[p2++] = (point){x,y,p1,6};
                vis[x][y] = true;
            }
            p1++;
        }
        if (!ans) puts("impossible");
    }
	return 0;
}

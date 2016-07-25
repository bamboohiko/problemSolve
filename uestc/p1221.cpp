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
const int n = 9;
const int add[4][2] = {0,1,0,-1,1,0,-1,0};
struct point {
    int x,y;
};
bool vis[20][20];
char a[20][20];
int dfs(int x,int y) {
    int ans = 0;
    a[x][y] = 'x';
    for (int i = 0;i < 4; i++) {
        int nx = x + add[i][0],ny = y + add[i][1];
        if (!vis[nx][ny]) {
            vis[nx][ny] = true;
            if (a[nx][ny] == '.') ans++;
            if (a[nx][ny] == 'o') ans += dfs(nx,ny);
        }
    }
    return ans;
}
int main() {
    for (int i = 0;i <= n+1; i++)
        for (int j = 0;j <= n+1; j++) a[i][j] = 'x';
    int t;char ch;
    scanf("%d%*c",&t);
    for (int ca = 1;ca <= t;ca++) {
        queue<point> Q;
        for (int i = 1;i <= n; i++) {
            scanf("%*c");
            for (int j = 1;j <= n; j++) {
                scanf("%c",&a[i][j]);
            }
        }
        getchar();
        /*
        for (int i = 1;i <= n; i++) {
            for (int j = 1;j <= n; j++) cout << a[i][j];
            cout << endl;
        }
        */
        bool ok = false;
        for (int i = 1;i <= n; i++) {
            for (int j = 1;j <= n; j++) {
                memset(vis,0,sizeof(vis));
                if (a[i][j] == 'o' && dfs(i,j) == 1) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) printf("Case #%d: Can kill in one move!!!\n",ca);
        else printf("Case #%d: Can not kill in one move!!!\n",ca);
    }
	return 0;
}

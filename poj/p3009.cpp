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
const int mov[4][2] = {1,0,-1,0,0,1,0,-1};
int n,m,ans;
int a[30][30];
bool is_sta(int x,int y) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    return true;
}
void dfs(int x,int y,int step) {
    if (step > 10) return;
    for (int i = 0;i < 4; i++) {
        if (a[x+mov[i][0]][y+mov[i][1]] == 1) continue;
        int nx = x,ny = y;
        while (is_sta(nx,ny) && a[nx][ny] != 3 && a[nx][ny] != 1) {
            nx += mov[i][0];
            ny += mov[i][1];
        }
        if (!is_sta(nx,ny)) continue;
        if (a[nx][ny] == 3) {
            if (ans == -1) ans = step;
            else ans = min(ans,step);
        }
        if (a[nx][ny] == 1) {
            a[nx][ny] = 0;
            dfs(nx-mov[i][0],ny-mov[i][1],step+1);
            a[nx][ny] = 1;
        }
    }
}
int main() {
    while (scanf("%d%d",&m,&n) != EOF) {
        memset(a,0,sizeof(a));
        if (n == 0 && m == 0) break;
        int x,y;
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++) {
                scanf("%d",&a[i][j]);
                if (a[i][j] == 2) {x = i;y = j;}
            }
        ans = -1;
        dfs(x,y,1);
        printf("%d\n",ans);
    }
	return 0;
}

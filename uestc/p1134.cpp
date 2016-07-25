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
using namespace std;
const int ed = (1 << 10)-1;
const int inf = 1e9 + 7;
int f[15][15][1050],a[15][15];
int n = 10,m = 10;
int dfs(int x,int y,int s) {
    if (x > n || y > m) return inf;
    if (x == n && y == m && s == ed) return 0;
    if (f[x][y][s]) return f[x][y][s];
    f[x][y][s] = min(dfs(x+1,y,s|(1 << a[x+1][y])) + a[x+1][y],dfs(x,y+1,s|(1 << a[x][y+1])) + a[x][y+1]);
    return f[x][y][s];
}
int main() {
    for (int i = 1;i <= n; i++)
        for (int j = 1;j <= m; j++) {
            scanf("%d",&a[i][j]);
        }
    printf("%d\n",dfs(1,1,(1 << a[1][1])) + a[1][1]);
	return 0;
}

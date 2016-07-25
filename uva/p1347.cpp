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
struct point {
    int x,y;
    bool operator <(const point& rhs) {
        return x < rhs.x;
    }
};
point p[1010];
double f[1010][1010];
bool vis[1010][1010];
int n;
double dis(int a,int b) {
    int x = p[a].x - p[b].x,y = p[a].y - p[b].y;
    return sqrt(x*x + y*y);
}
double dfs(int i,int j) {
    //cout << i << " " << j << endl;
    if (vis[i][j]) return f[i][j];
    if (i == n) return dis(i,j);
    f[i][j] = min(dfs(i+1,j)+dis(i,i+1),dfs(i+1,i)+dis(j,i+1));
    vis[i][j] = true;
    return f[i][j];
}
int main() {
    while (scanf("%d",&n) != EOF) {
        for (int i = 1;i <= n; i++) scanf("%d%d",&p[i].x,&p[i].y);
        memset(vis,false,sizeof(vis));
        printf("%.2lf\n",dfs(2,1)+dis(1,2));
    }
	return 0;
}

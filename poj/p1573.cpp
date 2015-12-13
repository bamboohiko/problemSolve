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
const int mov[4][2] = {-1,0,1,0,0,1,0,-1};
int n,m,k;
char a[1010][1010];
int vis[1010][1010];
map<char,int> dir;
bool is_sta(int x,int y) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    return true;
}
int main() {
    dir['N'] = 0;dir['S'] = 1;dir['E'] = 2;dir['W'] = 3;
    while (scanf("%d%d%d%*c",&n,&m,&k) != EOF) {
        memset(vis,0,sizeof(vis));
        if (n == 0 && m == 0 && k == 0) break;
        for (int i = 1;i <= n; i++) {
            for (int j = 1;j <= m; j++) scanf("%c",&a[i][j]);
            scanf("%*c");
        }
        int x = 1,y = k,cou = 1;
        int s1 = 0,s2 = 0;
        vis[x][y] = 1;
        while (true) {
            int d = dir[a[x][y]];
            x += mov[d][0];
            y += mov[d][1];
            //cout << x <<":" << y << endl;
            if (!is_sta(x,y)) {
                s1 = cou;
                break;
            }
            if (vis[x][y]) {
                s1 = vis[x][y] - 1;
                s2 = cou - vis[x][y] + 1;
                break;
            }
            vis[x][y] = ++cou;
        }
        if (s2) printf("%d step(s) before a loop of %d step(s)\n",s1,s2);
        else printf("%d step(s) to exit\n",s1);
    }
	return 0;
}

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
const int add[4][2] = {1,0,-1,0,0,1,0,-1};
int a[10][10],c[30];
int n,m,k;
struct point {
    int x,y;
};
void print() {
    puts("YES");
    for (int i = 1;i <= n; i++) {
        for (int j = 1;j < m; j++)
            printf("%d ",a[i][j]);
        printf("%d\n",a[i][m]);
    }
}
bool can(point p) {
    if (p.x <= 0 || p.x > n || p.y <= 0 || p.y > m) return false;
    return true;
}
bool build() {
    int cnt = 0;
    memset(a,0,sizeof(a));
    queue<point> Q;
    Q.push((point){1,1});
    while (!Q.empty()) {
        cnt++;
        point s = Q.front();Q.pop();
        for (int i = 0;i < 4; i++) {
            point t;
            t.x = s.x + add[i][0];t.y = s.y + add[i][1];
            if (!a[t.x][t.y] && can(t)) {
                for (int i = k;i >= 1; i--)
                if (c[i] && a[t.x-1][t.y] != i && a[t.x][t.y-1] != i) {
                    a[t.x][t.y] = i;
                    c[i]--;
                    Q.push(t);
                    break;
                }
                if (!a[t.x][t.y]) return false;
            }
        }
    }
    if (cnt == n*m) {
        print();
        return true;
    } else return false;
}
/*
bool dfs(int p) {
    if (p > m*n) {
        print();
        return true;
    }
    int x = (p-1)/m + 1,y = (p-1)%m+1;
    //cout << x << " " << y << endl;
    for (int i = 1;i <= k; i++)
        if (c[i] && a[x-1][y] != i && a[x][y-1] != i) {
            c[i]--;
            a[x][y] = i;
            if (dfs(p+1)) return true;
            c[i]++;
        }
    return false;
}
*/
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 1;i <= k; i++) scanf("%d",&c[i]);
        sort(c+1,c+k+1);
        printf("Case #%d:\n",ca);
        if (!build()) puts("NO");
    }
	return 0;
}


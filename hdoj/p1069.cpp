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
const int inf = 1e9 + 10;
struct cube {
    int x,y,z;
    cube(int _x = 0,int _y = 0, int _z = 0):x(_x),y(_y),z(_z) {}
};
cube a[40];
int f[40][3],n;
bool can(int k1,int t1,int k2,int t2) {
    int h1,d1,h2,d2;
    if (t1 == 0) {h1 = a[k1].x;d1 = a[k1].y;}
    if (t1 == 1) {h1 = a[k1].x;d1 = a[k1].z;}
    if (t1 == 2) {h1 = a[k1].y;d1 = a[k1].z;}

    if (t2 == 0) {h2 = a[k2].x;d2 = a[k2].y;}
    if (t2 == 1) {h2 = a[k2].x;d2 = a[k2].z;}
    if (t2 == 2) {h2 = a[k2].y;d2 = a[k2].z;}

    if (h1 < h2 && d1 < d2) return true;
    if (h1 < d2 && d1 < h2) return true;
    return false;
}
int dfs(int k,int d) {
    if (f[k][d]) return f[k][d];
    int h;
    if (d == 0) h = a[k].z;
    if (d == 1) h = a[k].y;
    if (d == 2) h = a[k].x;

    for (int i = 1;i <= n; i++)
        for (int j = 0;j < 3; j++)
            if (can(k,d,i,j)) f[k][d] = max(f[k][d],dfs(i,j));
    f[k][d] += h;
    return f[k][d];
}
int main() {
    int t = 1;
    while (scanf("%d",&n) != EOF && n) {
        memset(f,0,sizeof(f));
        for (int i = 1;i <= n; i++)
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        int ans = 0;
        for (int i = 1;i <= n; i++)
            for (int j = 0;j < 3; j++)
                ans = max(ans,dfs(i,j));
        printf("Case %d: maximum height = %d\n",t++,ans);
    }
	return 0;
}


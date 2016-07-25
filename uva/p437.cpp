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
int f[50][3],n;
int a[50],b[50],c[50];
bool can(int k1,int t1,int k2,int t2) {
    int h1,d1,h2,d2;
    if (t1 == 0) {h1 = a[k1];d1 = b[k1];}
    if (t1 == 1) {h1 = a[k1];d1 = c[k1];}
    if (t1 == 2) {h1 = b[k1];d1 = c[k1];}

    if (t2 == 0) {h2 = a[k2];d2 = b[k2];}
    if (t2 == 1) {h2 = a[k2];d2 = c[k2];}
    if (t2 == 2) {h2 = b[k2];d2 = c[k2];}

    if (h1 < h2 && d1 < d2) return true;
    if (h1 < d2 && d1 < h2) return true;
    return false;
}
int dfs(int k,int t) {
    if (f[k][t]) return f[k][t];

    int h;
    if (t == 0) h = c[k];
    if (t == 1) h = b[k];
    if (t == 2) h = a[k];

    f[k][t] = 0;
    for (int i = 1;i <= n; i++)  {
            for (int j = 0;j < 3; j++)
                if (can(i,j,k,t)) f[k][t] = max(f[k][t],dfs(i,j));
    }
    f[k][t] += h;
    return f[k][t];
}
int main() {
    int ca = 1;
    while (scanf("%d",&n) != EOF && n) {
        memset(f,0,sizeof(f));
        for (int i = 1;i <= n; i++) {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        int ans = 0;
        for (int i = 1;i <= n; i++) {
            for (int j = 0;j < 3; j++) {
                int k = dfs(i,j);
                ans = max(ans,k);
            }
        }
        printf("Case %d: maximum height = %d\n",ca++,ans);
    }
	return 0;
}

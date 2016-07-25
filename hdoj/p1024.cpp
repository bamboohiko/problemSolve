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
#define max(a,b) ((a>b)?a:b)
const int inf = 1e9 + 7;
const int maxn = 1e6 + 10;
int f[maxn][2],g[maxn][2];
int a[maxn];
int main() {
    int n,m;
    int now,la;
    while (scanf("%d%d",&m,&n) != EOF) {
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        for (int j = 1;j <= m; j++) {
            now = j&1,la = 1 - now;
            f[j-1][now] = g[j-1][now] = -inf;
            for (int i = j;i <= n; i++) {
                f[i][now] = max(f[i-1][now],max(f[i-1][la],g[i-1][la]))+a[i];
                g[i][now] = max(f[i-1][now],g[i-1][now]);
                //cout << f[i][now] << ":" << g[i][now] << endl;
            }
        }
        printf("%d\n",max(f[n][m&1],g[n][m&1]));
    }
	return 0;
}


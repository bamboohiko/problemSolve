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
const int INF = 1e9 + 7;
int a[210],has[210][60][2],f[210][60];
int main() {
    int n,ca = 1;
    while (scanf("%d",&n) != EOF && n) {
        memset(a,0,sizeof(a));
        memset(has,0,sizeof(has));
        memset(f,0,sizeof(f));
        int m,t;
        scanf("%d",&t);
        for (int i = 1;i < n; i++) scanf("%d",&a[i]);
        scanf("%d",&m);
        for (int j = 1;j <= m; j++) {
            int sumt;
            scanf("%d",&sumt);
            for (int i = 1;i <= n; i++) {
                has[sumt][i][1] = 1;
                sumt += a[i];
                if (sumt > t) break;
            }
        }
        scanf("%d",&m);
        for (int j = 1;j <= m; j++) {
            int sumt;
            scanf("%d",&sumt);
            for (int i = n;i >= 1; i--) {
                has[sumt][i][0] = 1;
                sumt += a[i-1];
                if (sumt > t) break;
            }
        }
        for (int i = 2;i <= n; i++) f[0][i] = INF;
        f[0][1] = 0;
        for (int i = 1;i <= t; i++) {
            for (int j = 1;j <= n; j++) {
                f[i][j] = f[i-1][j] + 1;
                if (j > 1 && has[i][j][1] && i >= a[j-1])
                    f[i][j] = min(f[i][j],f[i-a[j-1]][j-1]);
                if (j < n && has[i][j][0] && i >= a[j])
                    f[i][j] = min(f[i][j],f[i-a[j]][j+1]);
                //cout << f[i][j] << " ";
            }
            //cout << endl;
        }
        printf("Case Number %d: ",ca++);
        if (f[t][n] > t) printf("impossible\n");
        else printf("%d\n",f[t][n]);
    }
	return 0;
}

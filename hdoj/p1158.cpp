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
int a[20],f[20][1010];
int main() {
    int n;
    while (scanf("%d",&n) != EOF && n) {
        int hir,sal,fir,m = 0;
        scanf("%d%d%d",&hir,&sal,&fir);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            m = max(m,a[i]);
        }
        memset(f,INF,sizeof(f));
        for (int i = a[1];i <= m; i++) f[1][i] = i*(hir+sal);
        for (int i = 2;i <= n; i++)
            for (int j = a[i];j <= m; j++)  {
                for (int k = a[i-1];k <= m; k++) {
                    if (j >= k) f[i][j] = min(f[i][j],f[i-1][k]+j*sal+(j-k)*hir);
                    else f[i][j] = min(f[i][j],f[i-1][k]+j*sal+(k-j)*fir);
                }
                //printf("%d %d %d\n",i,j,f[i][j]);
            }
        int ans = INF;
        for (int i = a[n];i <= m; i++)
            ans = min(ans,f[n][i]);
        printf("%d\n",ans);
    }
	return 0;
}

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
typedef long long LL;
int f[110][110][4],a[110][110];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++)
        for (int j = 1;j <= m; j++) {
            scanf("%d",&a[i][j]);
        }
    int ans = n+1,x = -1,y = -1;
    for (int i = 1;i <= m; i++)
        for (int j = i+1;j <= m; j++) {
                for (int k = 1;k <= n; k++)
                    f[i][j][a[k][i]*2+a[k][j]]++;
                int mi = max(max(f[i][j][0],f[i][j][1]),max(f[i][j][2],f[i][j][3]));
                //cout<< i << " " << j << mi << endl;
                if (mi < ans) {
                    ans = mi;
                    x = i;y = j;
                }
            }
    printf("%d\n%d %d\n",ans,x,y);
	return 0;
}

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
int a[110][110],f[110][110][4];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int k = 1;k <= n; k++) {
        for (int i = 1;i <= m; i++) scanf("%d",&a[k][i]);
        for (int i = 1;i <= m; i++)
            for (int j = i+1;j <= m; j++) {
                    f[i][j][a[k][i]*2+a[k][j]]++;
            }
    }
    int ans = n+1,x,y;
    for (int i = 1;i <= m; i++)
        for (int j = i+1;j <= m; j++) {
            int rec = f[i][j][0];
            for (int k = 1;k < 4; k++) rec = max(rec,f[i][j][k]);
            //cout << i << " " << j << " " << rec << endl;
            if (rec < ans) {
                ans = rec;
                x = i;y = j;
            }
        }
    printf("%d\n%d %d\n",ans,x,y);
	return 0;
}

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
int val[30][30],v[30],f[110][110];
char a[110],b[110];
int main() {
    val[0][0] = 5;val[0][2] = -1;val[0][6] = -2;val[0][19] = -1;
    val[2][0] = -1;val[2][2] = 5;val[2][6] = -3;val[2][19] = -2;
    val[6][0] = -2;val[6][2] = -3;val[6][6] = 5;val[6][19] = -2;
    val[19][0] = -1;val[19][2] = -2;val[19][6] = -2;val[19][19] = 5;
    v[0] = -3;v[2] = -4;v[6] = -2;v[19] = -1;
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m;
        memset(f,0,sizeof(f));
        scanf("%d%*c",&n);for (int i = 1;i <= n; i++) scanf("%c",&a[i]);
        scanf("%d%*c",&m);for (int i = 1;i <= m; i++) scanf("%c",&b[i]);
        for (int i = 1;i <= n; i++) f[i][0] = f[i-1][0] + v[a[i]-'A'];
        for (int j = 1;j <= m; j++) f[0][j] = f[0][j-1] + v[b[j]-'A'];
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++) {
                f[i][j] = max(f[i-1][j-1]+val[a[i]-'A'][b[j]-'A'],max(f[i][j-1]+v[b[j]-'A'],f[i-1][j]+v[a[i]-'A']));
            }
        printf("%d\n",f[n][m]);
    }
	return 0;
}

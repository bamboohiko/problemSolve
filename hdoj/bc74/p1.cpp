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
const LL mod = 1e9 + 7;
int p[10],a[10][10];
int main() {
    int t,n,m;
    scanf("%d",&t);
    while (t--) {
        memset(a,sizeof(a),0);
        scanf("%d%d",&n,&m);
        int from,to;
        scanf("%d%d%d%d%d%d",&p[1],&p[2],&p[3],&p[4],&p[5],&p[6]);
        for (int i = 1;i <= 6; i++)
            for (int j = 1;j <= 6; j++)
                a[i][j] = abs(p[i] - p[j]);
        a[1][2] = a[3][4] = a[5][6] = 1;
        a[2][1] = a[4][3] = a[6][5] = 1;
        for (int k = 1;k <= 6; k++)
            for (int i = 1;i <= 6; i++)
                for (int j = 1;j <= 6; j++)
                    if (i != j) a[i][j] = min(a[i][j],a[i][k] + a[k][j]);
        LL ans = 0;
        for (int x = 1;x <= m; x++) {
            scanf("%d%d",&from,&to);
            LL k = abs(from - to);
            for (int i = 1;i <= 6; i++)
                for (int j = 1;j <= 6; j++)
                    k = min(k,(LL)abs(from-p[i]) + a[i][j] + abs(to-p[j]));
            //cout << k << endl;
            ans = (ans + k*x)%mod;
        }
        printf("%lld\n",ans);
    }
	return 0;
}


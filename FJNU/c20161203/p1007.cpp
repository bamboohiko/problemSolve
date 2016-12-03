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
LL a[10010],b[10010],f[10010][20][2];
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,k;
        scanf("%d%d",&n,&k);
        for (int i = 1;i <= n; i++) scanf("%I64d",&a[i]);
        for (int i = 1;i <= n; i++) scanf("%I64d",&b[i]);
        for (int i = 1;i <= n; i++) {
            f[i][0][0] = f[i-1][0][0] + a[i];
            f[i][0][1] = f[i-1][0][1] + b[i];
            for (int j = 1;j <= k; j++) {
                f[i][j][0] = min(f[i-1][j][0]+a[i],f[i-1][j-1][1]+b[i]);
                f[i][j][1] = min(f[i-1][j-1][0]+a[i],f[i-1][j][1]+b[i]);
            }
        }
        cout << min(f[n][k][0],f[n][k][1]) << endl;
    }
	return 0;
}


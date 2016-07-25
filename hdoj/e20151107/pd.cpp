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
const int maxn = 210;
int a[maxn],b[maxn],f[maxn][maxn];
int main() {
    int t,n;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        int sum = 0;
        memset(f,0,sizeof(f));
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        for (int i = 1;i <= n; i++) scanf("%d",&b[i]);b[0] = b[n+1] = 0;
        for (int len = 1;len < n;len++)
            for (int i = 1;i + len <= n;i++) {
                int j = i + len;
                f[i][j] = min(f[i+1][j]+b[i]+b[j+1],f[i][j-1]+b[j]+b[i-1]);
                for (int k = i+1;k < j; k++)
                    f[i][j] = min(f[i][j],f[i][k-1]+f[k+1][j]+b[k]*2+b[i-1]+b[j+1]);
            }
            /*
        for (int len = 1;len < n;len++) {
            for (int i = 1;i + len <= n;i++) {
                int j = i + len;
                cout << f[i][j] << " ";
            }
            cout << endl;
        }
            */
        printf("Case #%d: %d\n",ca, sum + f[1][n]);
    }
	return 0;
}

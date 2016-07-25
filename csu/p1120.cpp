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
const int maxn = 1010;
int a[maxn],b[maxn],f[maxn][maxn];
int main() {
    int t,n,m;
    scanf("%d",&t);
    while (t--) {
        memset(f,0,sizeof(f));
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        scanf("%d",&m);
        for (int i = 1;i <= m; i++) scanf("%d",&b[i]);
        int ans = 0;
        for (int i = 1;i <= n; i++) {
            int k = 0;
            for (int j = 1;j <= m; j++) {
                f[i][j] = f[i-1][j];
                if (a[i] == b[j]) {
                    f[i][j] = max(f[i][j],k+1);
                }
                if (a[i] > b[j]) {
                    k = max(k,f[i-1][j]);
                }
                ans = max(ans,f[i][j]);
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}


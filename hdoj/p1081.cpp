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
const int maxn = 100 + 10;
int a[110][110],s[110][110],f[110];
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        int ans = -200;
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= n; j++) {
                scanf("%d",&a[i][j]);
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
            }
        for (int i = 1;i <= n; i++)
            for (int j = i;j <= n; j++)
                for (int k = 1;k <= n; k++) {
                    f[k] = max(f[k-1],0) + s[j][k] - s[i-1][k] - s[j][k-1] + s[i-1][k-1];
                    ans = max(f[k],ans);
                }
        printf("%d\n",ans);
    }
	return 0;
}


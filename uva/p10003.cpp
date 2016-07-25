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
const int inf = 1e8 + 7;
int a[100],f[100][100];
int main() {
    int d,n;
    while (scanf("%d",&d) != EOF && d) {
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);a[0] = 0;a[n+1] = d;
        for (int len = 1;len <= n; len++)
            for (int l = 0;l + len <= n; l++) {
                int r = l + len;
                f[l][r] = inf;
                for (int k = l+1;k <= r; k++)
                    f[l][r] = min(f[l][r],f[l][k-1]+f[k][r]);
                f[l][r] += a[r+1]-a[l];
            }
        printf("The minimum cutting is %d.\n",f[0][n]);
    }
	return 0;
}

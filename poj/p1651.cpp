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
const int inf = 1e9 + 7;
int f[110][110],a[110];
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        for (int len = 0;len < n; len++)
            for (int i = 2;i + len < n; i++) {
                int j = i + len;
                f[i][j] = inf;
                for (int k = i;k <= j; k++)
                    f[i][j] = min(f[i][j],f[i][k-1]+f[k+1][j]+a[k]*a[i-1]*a[j+1]);
            }
        printf("%d\n",f[2][n-1]);
    }
	return 0;
}

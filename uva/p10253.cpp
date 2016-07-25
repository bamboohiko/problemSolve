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
typedef long long LL;
const int maxn = 30;
LL f[40],d[40][40];
LL c(LL n,LL m) {
    double ans = 1;
    for (LL i = n;i > n-m; i--) ans *= i;
    for (LL i = 2;i <= m; i++) ans /= i;
    return (LL)(ans + 0.5);
}
int main() {
    for (int i = 0;i <= maxn; i++) d[i][0] = 1;
    for (int i = 1;i <= maxn; i++) d[i][1] = 1;
    f[1] = 1;
    for (int i = 1;i <= maxn; i++) {
        for (int j = 2;j <= maxn; j++) {
            for (int p = 0;p*i <= j; p++)
                d[i][j] += c(f[i]+p-1,p)*d[i-1][j-p*i];
        }
        f[i+1] = d[i][i+1];
    }
    int n;
    while (scanf("%d",&n) != EOF && n) {
        if (n == 1) printf("%d\n",f[n]);
        else printf("%lld\n",f[n]*2);
    }
	return 0;
}

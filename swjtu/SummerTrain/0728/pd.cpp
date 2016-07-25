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
const double eps = 1e-7;
double a[20][20];
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    return x > 0?1:-1;
}
int main() {
    int n;
    while (scanf("%d",&n) != EOF && n) {
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= n; j++)
                scanf("%lf",&a[i][j]);
        double ans = 1;
        for (int k = 2;k <= n; k++) {
            if (sgn(a[k-1][k-1]) == 0)
                for (int i = k;i <= n; i++) {
                    if (sgn(a[i][k-1]) != 0) {
                        for (int j = 1;j <= n; j++) swap(a[k-1][j],a[i][j]);
                        ans *= -1;
                        break;
                    }
                }
            for (int i = k;i <= n; i++) {
                if (sgn(a[i][k-1]) == 0) continue;
                double c = -a[i][k-1]/a[k-1][k-1];
                for (int j = k;j <= n; j++)
                    a[i][j] += c*a[k-1][j];
            }
        }
        for (int i = 1;i <= n; i++)
            ans *= a[i][i];
        double k = sgn(ans)*fabs(ans);
        printf("%.0lf\n",k);
    }
	return 0;
}

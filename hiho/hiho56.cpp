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
#define eps 1e-6
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
double a[1010][1010],val[1010],b[1010];
int loc[1010];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int j = 1;j <= m; j++) {
        for (int i = 1;i <= n; i++) scanf("%lf",&a[j][i]);
        scanf("%lf",&b[j]);
    }
    for (int i = 1;i <= m; i++) loc[i] = i;
    int sol = 0;
    for (int i = 1;i <= n; i++) {
        bool flag = false;
        for (int j = i;j <= m; j++) {
            if (fabs(a[loc[j]][i]) > eps) {
                swap(loc[i],loc[j]);
                flag = true;
                break;
            }
        }
        if (!flag) {
            sol = 1;
            break;
        }
        for (int j = i+1;j <= m; j++)
            if (fabs(a[loc[i]][i]) > eps) {
                double x = a[loc[j]][i]/a[loc[i]][i];
                for (int k = i;k <= n; k++) a[loc[j]][k] -= x*a[loc[i]][k];
                b[loc[j]] -= x*b[loc[i]];
            }
    }
    for (int j = 1;j <= m; j++) {
        bool flag = false;
        for (int i = 1;i <= n; i++)
            if (fabs(a[loc[j]][i]) > eps) {
                flag = true;
                break;
            }
        if (!flag && fabs(b[loc[j]]) > eps) {
            sol = -1;
            break;
        }
    }
    if (!sol) {
        for (int j = n;j >= 1; j--) {
            for (int i = j+1;i <= n; i++) {
                b[loc[j]] -= a[loc[j]][i]*val[i];
                a[loc[j]][i] = 0;
            }
            val[j] = b[loc[j]]/a[loc[j]][j];
        }
        for (int i = 1;i <= n; i++)
            if (fabs(val[i]) < eps) puts("0");
            else printf("%.0lf\n",val[i]+eps);
    } else {
        if (sol == 1) puts("Many solutions");
        if (sol == -1) puts("No solutions");
    }
	return 0;
}

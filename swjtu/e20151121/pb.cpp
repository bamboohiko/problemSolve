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
#define eps 1e-12
#define pi acos(-1.0)
using namespace std;
double a[110];
int n;
double fig(double h) {
    double ans = 0;
    for (int i = 1;i <= n; i++) {
        if (h < a[i]) ans += a[i]*a[i]*h;
        else ans += a[i]*a[i]*a[i];
    }
    return ans;
}
int main() {
    freopen("data.in","r",stdin);
    freopen("data2.out","w",stdout);
    while (scanf("%d",&n) != EOF) {
        double l = 0,r = 2000,sum = 0;
        for (int i = 1;i <= n; i++)  {
            scanf("%lf",&a[i]);
            sum += a[i]*a[i]*a[i];
        }
        sum /= 2;
        while (abs(r-l) > eps) {
            double mid = (l+r)/2;
            double rec = fig(mid);
            if (rec > sum) r = mid;
            else l = mid;
        }
        printf("%.4lf\n",l);
    }
	return 0;
}

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
struct point {
    double s,t;
    bool operator <(const point &rhs) const {
        return t < rhs.t;
    }
};
point a[1010];
int main() {
    int n,cou = 0;double d,x,y;
    while (scanf("%d%lf",&n,&d) != EOF) {
        if (n == 0 && d == 0) break;
        int ans = 0;double x0;
        if (d < 0) ans = -1;
        for (int i = 1;i <= n; i++) {
            scanf("%lf%lf",&x,&y);
            if (y > d) {
                ans = -1;
            } else {
                double dx = sqrt(d*d - y*y);
                a[i].s = x - dx;a[i].t = x + dx;
            }
        }
        sort(a+1,a+n+1);
        if (ans == 0) {
            ans = 1;x0 = a[1].t;
            for (int i = 2;i <= n; i++) {
                if (a[i].s > x0) {
                    x0 = a[i].t;
                    ans++;
                }
            }
        }
        printf("Case %d: %d\n",++cou,ans);
    }
	return 0;
}


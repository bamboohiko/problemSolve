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
struct point {
    double x,y;
    point(int _x = 0,int _y = 0):x(x),y(y) {}
    point operator -(point rhs) {
        return point(x - rhs.x, y - rhs.y);
    }
    double operator ^(point rhs) {
        double ans = x*rhs.y - y*rhs.x;
        return ans;
    }
    double operator *(point rhs) {
        return x*rhs.x + y*rhs.y;
    }
};
struct Line {
    point s,e;
};
Line a[110];
bool sgn(double x) {
    if (fabs(x) < eps) return 0;
    return (x > 0)?1:-1;
}
bool inter(Line l1,Line l2)
{
  return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}
int main() {
    int n;
    while (scanf("%d",&n) != EOF && n) {
        for (int i = 1;i <= n; i++) {
            cin >> a[i].s.x >> a[i].s.y >> a[i].e.x >> a[i].e.y;
            //scanf("%lf%lf",&a[i].s.x,&a[i].s.y);
            //scanf("%lf%lf",&a[i].e.x,&a[i].e.y);
            //printf("%lf %lf %lf %lf\n",a[i].s.x,a[i].s.y,a[i].e.x,a[i].e.y);
        }
        int ans = 0;
        for (int i = 1;i < n; i++)
            for (int j = i+1;j <= n; j++)
            if (inter(a[i],a[j])) ans++;
        printf("%d\n",ans);
    }
	return 0;
}

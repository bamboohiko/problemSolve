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
const double eps = 1e-9;
const int MAXN = 2e5 + 100;
struct Point {
    double x,y;
    Point() {}
    Point(double _x,double _y) {
        x = _x;y = _y;
    }
    Point operator -(const Point& b) const {
        return Point(x - b.x,y - b.y);
    }
    double operator ^(const Point& b) const {
        return x*b.y - y*b.x;
    }
};
Point a[MAXN];
int s[MAXN],top;
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    else return 1;
}
double dis(Point a,Point b) {
    double x = a.x - b.x,y = a.y - b.y;
    return sqrt(x*x+y*y);
}
bool cmp(Point p1,Point p2) {
    double tmp = (p1 - a[0])^(p2 - a[0]);
    if (sgn(tmp) > 0) return true;
    else if (sgn(tmp) == 0 && sgn(dis(p1,a[0]) - dis(p2,a[0])) <= 0)  return true;
    else return false;
}
void graham(int n) {
    Point p0;
    int k = 0;
    p0 = a[0];
    for (int i = 1;i < n; i++) {
        if ((p0.y > a[i].y) || (p0.y == a[i].y && p0.x > a[i].x)) {
            p0 = a[i];
            k = i;
        }
    }
    swap(a[k],a[0]);
    sort(a+1,a+n,cmp);
    s[0] = 0;s[1] = 1;top = 2;
    if (n == 1) {
        top = 1;
        return;
    }
    if (n == 2) {
        top = 2;
        return;
    }
    for (int i = 2;i < n; i++) {
        while (top > 1 && sgn((a[s[top-1]]-a[s[top-2]])^(a[i]-a[s[top-2]])) <= 0) top--;
        s[top++] = i;
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        for (int i = 0;i < n; i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        graham(n);
        double res = 0;
        for (int i = 0;i < top; i++)
            res += (a[s[i]]^a[s[(i+1)%top]])/2;
        printf("%.1lf\n",res);
    }
	return 0;
}



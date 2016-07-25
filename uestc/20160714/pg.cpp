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
    double x,y;
    point(double _x = 0,double _y = 0) {
        x = _x;y = _y;
    }
    bool operator ==(point rhs) {
        if (x == rhs.x && y == rhs.y) return true;
        return false;
    }
    point operator +(point rhs) {
        return point(x + rhs.x,y + rhs.y);
    }
    point operator -(point rhs) {
        return point(x - rhs.x,y - rhs.y);
    }
    double operator ^(point rhs) {
        return x*rhs.y - y*rhs.x;
    }
    double operator *(point rhs) {
        return x*rhs.x + y*rhs.y;
    }
};
double dis(point a,point b) {
    double dx = a.x-b.x,dy = a.y-b.y;
    return sqrt(dx*dx + dy*dy);
}
int sgn(double a) {
    if (abs(a) < eps) return 0;
    if (a > 0) return 1;
    else return -1;
}
double dis2(point p,point p2,point p4) {
    double d;
    double t = ((p-p2)*(p4-p2))/((p4-p2)*(p4-p2));
    if (t >= 0 && t <= 1) {
        double h = dis(p2,p4);
        d = abs((p2-p)^(p4-p))/h;
    } else d = min(dis(p,p2),dis(p,p4));
    return d;
}
int main() {
    point p1,p2,p3,p4;
    scanf("%lf%lf",&p1.x,&p1.y);
    scanf("%lf%lf",&p2.x,&p2.y);
    scanf("%lf%lf",&p3.x,&p3.y);p3 = p1 + p3;
    scanf("%lf%lf",&p4.x,&p4.y);p4 = p2 + p4;
    double ans;
    if (p1 == p3 && p2 == p4) {
        ans = dis(p1,p2);
    } else if (p1 == p3 || p2 == p4){
        if (p1 == p3) ans = dis2(p1,p2,p4);
        else ans = dis2(p2,p1,p3);
    } else if (sgn((p2-p1)^(p3-p1))*sgn((p4-p1)^(p3-p1)) <= 0 &&
        sgn((p1-p2)^(p4-p2))*sgn((p3-p2)^(p4-p2)) <= 0) {
            ans = 0;
    } else {
        double d1 = min(dis2(p1,p2,p4),dis2(p3,p2,p4));
        double d2 = min(dis2(p2,p1,p3),dis2(p4,p1,p3));
        ans = min(d1,d2);
    }
    printf("%lf",ans);
	return 0;
}

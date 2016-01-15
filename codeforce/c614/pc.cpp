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
    point(double _x = 0,double _y = 0) {x = _x;y = _y;}
    point operator -(point rhs) {
        return point(x - rhs.x,y - rhs.y);
    }
    point operator +(point rhs) {
        return point(x + rhs.x,y + rhs.y);
    }
    double operator ^(point rhs) {
        return x*rhs.y - rhs.x*y;
    }
};
double dis(point a,point b) {
    double x = a.x - b.x,y = a.y - b.y;
    return sqrt(x*x + y*y);
}
double dis(point p,point s,point t) {
    point tmp = p;
    tmp.x += s.y - t.y;
    tmp.y += t.x - s.x;
    if(((p-s)^(tmp-s))*((p-t)^(tmp-t)) >= 0)
        return min(dis(p,s), dis(p,t));
    return fabs((s-p)^(t-p)) / dis(s,t);
}
int main() {
    int n;point s1,p,s,t;
    scanf("%d%lf%lf",&n,&p.x,&p.y);
    double maxv = 0,minv = INF,d;
    scanf("%lf%lf",&s.x,&s.y);s1 = s;
    d = dis(p,s);maxv = max(d,maxv);
    for (int i = 2;i <= n; i++) {
        scanf("%lf%lf",&t.x,&t.y);
        d = dis(p,t);
        maxv = max(d,maxv);
        d = dis(p,s,t);
        minv = min(d,minv);
        s = t;
    }
    d = dis(p,s,s1);minv = min(d,minv);
    printf("%.18lf",(maxv*maxv-minv*minv)*pi);
	return 0;
}


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
    double dis(point &p) {
        double dx = x - p.x,dy = y - p.y;
        return sqrt(dx*dx+dy*dy);
    }
};
int main() {
    point p,p1;
    scanf("%lf%lf",&p.x,&p.y);
    int n;
    double ans = 1e6,v;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%lf%lf%lf",&p1.x,&p1.y,&v);
        double t = p.dis(p1)/v;
        ans = min(ans,t);
    }
    printf("%.20lf",ans);
	return 0;
}

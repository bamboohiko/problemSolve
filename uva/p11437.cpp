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
struct point {
    double x,y;
    point(double _x = 0,double _y = 0):x(_x),y(_y) {}
    point operator +(point rhs) {
        return point(x+rhs.x,y+rhs.y);
    }
    point operator -(point rhs) {
        return point(x-rhs.x,y-rhs.y);
    }
    point operator *(double k) {
        return point(x*k,y*k);
    }
    double operator ^(point rhs) {
        return x*rhs.y - y*rhs.x;
    }
};
point a,b,c,A,B,C,m,n;
int main() {
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
        a = B-A;b = C-B;c = A-C;
        m = (a*(2.0/7)) - (c*(1.0/7));
        n = (b*(2.0/7)) - (a*(1.0/7));
        int ans = floor(abs(m^n)/2 + 0.5);
        printf("%d\n",ans);
    }
	return 0;
}


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
const double inf = 1e16 + 7;
const double eps = 1e-8;
struct point {
    double x,y;
    point operator -(point rhs) {
        point ans;
        ans.x = x - rhs.x;
        ans.y = y - rhs.y;
        return ans;
    }
};
point a[2010],p;
double b[2010];
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        for (int i = 1;i <= n; i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        bool ans = false;
        for (int i = 1;i < n; i++) {
            p = a[i];
            for (int j = 2;j <= n; j++) {
                point pt = a[j] - p;
                if (pt.x == 0) b[j-i] = inf;
                else b[j-i] = pt.y/pt.x;
            }
            sort(b+1,b+n-i+1);
            for (int j = 1;j < n-i; j++)
                if (abs(b[j+1]-b[j]) < eps) {
                    ans = true;
                    goto lambel;
                }
        }
        lambel:
            if (ans) printf("a is the lucky boy.\n");
            else {
                if (n%3) printf("a is the lucky boy.\n");
                else printf("b is the lucky boy.\n");
            }
    }
	return 0;
}

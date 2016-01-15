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
const int maxn = 1e5 + 10;
struct point {
    double x,y;
};
point a[maxn];
bool cmp(point a,point b) {
    if (abs(a.x - b.x) < eps) return a.y < b.y;
    return a.x < b.x;
}
int main() {
    int n;
    double l,r,k,b;
    scanf("%d",&n);
    scanf("%lf%lf",&l,&r);
    for (int i = 0;i < n; i++) {
        scanf("%lf%lf",&k,&b);
        a[i].x = k*l + b;
        a[i].y = k*r + b;
        //printf("%lf %lf\n",a[i].x,a[i].y);
    }
    sort(a,a+n,cmp);
    bool ans = false;int loc = 0;
    for (int i = 1;i < n; i++) {
        if (abs(a[i].x - a[i-1].x) > eps) {
            if (a[i-1].y > a[loc].y) loc = i-1;
            if (a[i].y < a[loc].y) {
                ans = true;
                break;
            }
        }
    }
    if (ans) puts("YES\n");
    else puts("NO\n");
	return 0;
}


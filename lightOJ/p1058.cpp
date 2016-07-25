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
const double eps = 1e-6;
struct point {
    double x,y;
};
point a[1010],b[1000100];
bool same(point a,point b) {
    if (abs(a.x - b.x) < eps && abs(a.y-b.y) < eps) return true;
    return false;
}
bool cmp(point a,point b) {
    if (a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        int n,m = 0;
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%lf%lf",&a[i].x,&a[i].y);
        for (int i = 1;i <= n; i++)
            for (int j = i+1;j <= n; j++) {
                double x = (a[i].x + a[j].x)/2,y = (a[i].y + a[j].y)/2;
                b[m].x = x;b[m++].y = y;
            }
        sort(b,b+m,cmp);
        int ans = 0,cnt = 1;
        for (int i = 1;i <= m; i++) {
            if (same(b[i],b[i-1])) cnt++;
            else {
                ans += cnt*(cnt-1)/2;
                cnt = 1;
            }
        }
        ans += cnt*(cnt-1)/2;
        printf("Case %d: %d\n",ca ,ans);
    }
	return 0;
}


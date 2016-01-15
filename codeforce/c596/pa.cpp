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
    int x,y;
};
point a[10];
bool cmp(point a,point b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    if (n == 1) printf("-1\n");
    else {
        int ans = abs((a[n].x-a[1].x)*(a[n].y - a[1].y));
        if (n == 3) {
            ans = max(ans,abs((a[2].x-a[1].x)*(a[1].y-a[2].y)));
            ans = max(ans,abs((a[2].x-a[3].x)*(a[2].y-a[3].y)));
        }
        if (ans) printf("%d\n",ans);
        else printf("-1\n");
    }
	return 0;
}

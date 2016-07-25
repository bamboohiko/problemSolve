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
    int x,y;
    point(int _x = 0,int _y = 0) {
        x = _x;y = _y;
    }
    point operator -(point rhs) {
        return point(x - rhs.x,y - rhs.y);
    }
    int operator ^(point rhs) {
        return x*rhs.y - y*rhs.x;
    }
};
point p[1010];
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n+1; i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    p[0] = p[n];
    int area = 0,ans = 0;
    for (int i = 2;i <= n+1; i++)
        area += p[i-1]^p[i];
    //cout << area << endl;
    for (int i = 1;i <= n; i++) {
        int res = (p[i]-p[i-1])^(p[i+1]-p[i-1]);
        //cout << res <<endl;
        if ((LL)area*res < 0) ans++;
    }
    printf("%d\n",ans);
	return 0;
}

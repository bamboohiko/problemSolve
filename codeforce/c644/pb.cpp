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
    LL num,x,y;
    point(LL _n = 0,LL _x = 0,LL _y = 0) {
        num = _n;x = _x;y = _y;
    }
};
queue<point> Q;
LL t[200100];
int main() {
    int n,m;LL x,y,time = 0;
    bool fir = true;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) {
        scanf("%I64d%I64d",&x,&y);
        while (!Q.empty()) {
            point p = Q.front();
            time = max(time,p.x);
            if (time + p.y <= x) {
                time = t[p.num] = time + p.y;
                Q.pop();
            } else break;
        }
        if (Q.size() <= m) Q.push(point(i,x,y));
        else t[i] = -1;
    }
    while (!Q.empty()) {
        point p = Q.front();Q.pop();
        time = max(time,p.x);
        time = t[p.num] = time + p.y;
    }
    for (int i = 1;i < n; i++) printf("%I64d ",t[i]);
    printf("%I64d\n",t[n]);
	return 0;
}


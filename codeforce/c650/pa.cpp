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
    bool operator <(const point &rhs) const {
        if (x == rhs.x) return y < rhs.y;
        else return x < rhs.x;
    }
};
map<int,LL> r,c;
map<point,LL> S;
int main() {
    int n;
    point p;
    LL ans = 0;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d%d",&p.x,&p.y);
            if (!r.count(p.x)) r[p.x] = 1;
            else r[p.x]++;
            if (!c.count(p.y)) c[p.y] = 1;
            else c[p.y]++;
            if (!S.count(p)) S[p] = 1;
            else S[p]++;
            ans += r[p.x]+c[p.y]-S[p]-1;

    }
    printf("%I64d\n",ans);
	return 0;
}

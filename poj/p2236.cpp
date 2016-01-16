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
};
point p[1010];
bool vis[1010];
int f[1010];
stack<int> S;
vector<int> v[1010];
double dis(point a,point b) {
    double x = a.x - b.x,y = a.y - b.y;
    return sqrt(x*x + y*y);
}
int find(int k) {
    while (f[k] != k) {
        S.push(k);
        k = f[k];
    }
    while (!S.empty()) {
        int p = S.top();S.pop();
        f[p] = k;
    }
    return k;
}
int main() {
    int n,a,b;double d;char ch;
    memset(vis,0,sizeof(vis));
    scanf("%d%lf",&n,&d);
    for (int i = 1;i <= n; i++) {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        f[i] = i;
    }
    for (int i = 1;i <= n; i++)
        for (int j = 1;j <= n; j++)
            if (i != j && dis(p[i],p[j]) <= d + eps)
                v[i].push_back(j);
    getchar();
    while ((ch = getchar())!= EOF) {
        if (ch == 'O') {
            scanf("%d",&a);
            vis[a] = true;
                for (int i = 0;i < v[a].size(); i++)
                    if (vis[v[a][i]]) {
                        int da = find(a),db = find(v[a][i]);
                        f[da] = db;
                    }
        } else {
            scanf("%d%d",&a,&b);
            a = find(a),b = find(b);
            if (a == b) puts("SUCCESS");
            else puts("FAIL");
        }
        getchar();
    }
	return 0;
}


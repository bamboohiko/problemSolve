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
int dfs(int s,int fa) {
    int lef = 0,sum = 0;
    int m1 = inf,m2 = inf;
    for (int i = head[s];i ;i = edge[i].next) {
        int t = edge[i].to;
        if (t == fa) continue;
        dfs(t);
        if (f[t][0] == 0) lef++;
        else {
            sum += f[t][0];
            if (f[t][1] - f[t][0] < m1) {
                m2 = m1;
                m1 = f[t][1] - f[t][0];
            } else if (f[t][1] - f[t][0] < m2) {
                m2 = f[t][1] - t[t][0];
            }
        }
    }
    if (lef == 1)
    if (m2 == inf) {
        if (m1 == inf) {
            f[t][0] == f[t][1] == 0;
        } else {
            f[t][0] == f[t][1] == sum;
        }
    } else {
        f[s][1] = m1 + sum;
        f[s][0] = m1 + m2 + sum + 1;
    }
    return f[s];
}
int main() {
    int n;
    while (scanf("%d".&n) != EOF) {
        memset(f,0,sizeof(f));
        int from,to;
        for (int i = 1;i < n; i++) {
            scanf("%d%d",&from,&to);
            build(from,to);
        }
        dfs(1,0)
        printf("%d\n",f[1][0]);
    }
	return 0;
}

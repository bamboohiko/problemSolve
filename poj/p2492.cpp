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
int f[2010],dis[2010];
stack<int> S;
int find(int k) {
    while (f[k] != k) {
        S.push(k);
        k = f[k];
    }
    while (!S.empty()) {
        int p = S.top();S.pop();
        dis[p] = (dis[p] + dis[f[p]])%2;
        f[p] = k;
    }
    return k;
}
int main() {
    int t;
    int n,m,a,b;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        printf("Scenario #%d:\n",ca);
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n; i++) {f[i] = i;dis[i] = 0;}
        bool ans = true;
        while (m--) {
            scanf("%d%d",&a,&b);
            int x = find(a),y = find(b);
            if (x == y && dis[a] == dis[b]) ans = false;
            f[x] = y;dis[x] = (dis[b] + 1 - dis[a])%2;
        }
        if (ans) puts("No suspicious bugs found!");
        else puts("Suspicious bugs found!");
        if (ca != t) puts("");
    }
	return 0;
}


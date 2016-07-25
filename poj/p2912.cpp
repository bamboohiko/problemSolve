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
int f[510],dis[510],vis[510];
stack<int> S;
int find(int k) {
    while (f[k] != k && f[k] != -1) {
        S.push(k);
        k = f[k];
    }
    while (!S.empty()) {
        int p = S.top();S.pop();
        dis[p] = (dis[p] + dis[f[p]])%3;
        f[p] = k;
    }
    return k;
}
int main() {
    int n,m;
    int a,b,c;
    char op;
    while (scanf("%d%d",&n,&m) != EOF) {
        for (int i = 0;i < n; i++) {f[i] = i;dis[i] = 0;}
        memset(vis,0,sizeof(vis));
        for (int i = 1;i <= m; i++) {
            scanf("%d%c%d",&a,&op,&b);
            if (op == '=') c = 0;
            else if (op == '>') c = 1;
            else c = 2;
            int x = find(a),y = find(b);
            if (x == -1 || y == -1) continue;
            //cout << dis[a] << " " << dis[b] << " " << c << endl;
            if (x == y && dis[a] != (dis[b] + c)%3) {
                if (vis[a] == -1 || vis[b] == -1) {
                    if (vis[a] == -1) {vis[a] = i;f[a] = -1;}
                    if (vis[b] == -1) {vis[b] = i;f[b] = -1;}
                }  else {
                    vis[a] = vis[b] = -1;
                }
            } else {
                f[x] = y;
                dis[x] = (c + dis[b] - dis[a] + 3)%3;
            }
            //cout << x << " " << y << endl;
        }
        int ans = -1,cou = 0;
        if (n == 1) ans = 0;
        for (int i = 0;i < n; i++) {
            //cout << vis[i] << " ";
            if (vis[i] > 0) {
                if (ans == -1) ans = i;
                else ans = -2;
            }
            if (vis[i] < 0) cou++;
        }
        //cout << endl;
        if (cou > 2 || ans == -2) puts("Impossible");
        else if (ans == -1) puts("Can not determine");
        else printf("Player %d can be determined to be the judge after %d lines\n",ans,vis[ans]);
    }
	return 0;
}


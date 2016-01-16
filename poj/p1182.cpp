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
const int maxn = 5e4 + 10;
int f[maxn],dis[maxn];
stack<int> S;
int find(int k) {
    while (f[k] != k) {
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
    int x,y,c,a,b;
    //while (scanf("%d%d",&n,&m) != EOF) {
    scanf("%d%d",&n,&m);
        int ans = 0;
        memset(dis,0,sizeof(dis));
        for (int i = 1;i <= n; i++) f[i] = i;
        while (m--) {
            //cout << ans << ":";
            scanf("%d%d%d",&c,&a,&b);
            if (a > n || b > n) {
                ans++;
                continue;
            }
            c--;
            x = find(a),y = find(b);
            //printf("%d %d %d %d %d\n",x,y,dis[a],dis[b],c);
            if (x == y && (dis[a]-dis[b] + 3)%3 != c) {
                ans++;
                //cout << ans << endl;
                continue;
            }
            f[x] = y;dis[x] = (c + dis[b] - dis[a] + 3)%3;
        }
        printf("%d\n",ans);
    //}
	return 0;
}


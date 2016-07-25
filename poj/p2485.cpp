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
int n,a[510][510];
bool vis[510];
queue<int> Q;
int bfs(int mid) {
    memset(vis,0,sizeof(vis));
    Q.push(1);vis[1] = true;
    int cou = 0;
    while (!Q.empty()) {
        int s = Q.front();Q.pop();
        cou++;
        for (int i = 1;i <= n; i++)
            if (!vis[i] && a[s][i] <= mid) {
                Q.push(i);
                vis[i] = true;
            }
    }
    return cou;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= n; j++)
                scanf("%d",&a[i][j]);
        int l = 0,r = 65537;
        while (r - l > 1) {
            int mid = (l + r)/2;
            if (bfs(mid) == n) r = mid;
            else l = mid;
        }
        printf("%d\n",r);
    }
	return 0;
}


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
    int s,t;
};
point a[110];
bool vis[110];
int main() {
    int n,T = 1;
    while (scanf("%d",&n) != EOF && n) {
        memset(vis,0,sizeof(vis));
        for (int i = 1;i <= n; i++) {
            scanf("%d%d",&a[i].s,&a[i].t);
            a[i].s *= 2;a[i].t *= 2;
        }
        int ans = 0;
        for (int i = 16;i < 48; i++) {
            int loc = 0,ed = 49;
            for (int j = 1;j <= n; j++) {
                if (!vis[j] && i >= a[j].s && i < a[j].t && a[j].t < ed) {loc = j;ed = a[j].t;}
            }
            if (loc) {
                vis[loc] = true;
                ans++;
            }
        }
        printf("On day %d Emma can attend as many as %d parties.\n",T++,ans);
    }
	return 0;
}

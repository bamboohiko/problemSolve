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
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn],b[maxn],f[maxn];
bool vis[maxn];
void dfs(int k) {
    //cout << k << " ";
    if (vis[f[k]]) return;
    vis[f[k]] = true;
    dfs(f[k]);
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&b[i]);
            f[a[i]] = b[i];
        }
        int ans = n;
        for (int i = 1;i <= n; i++)
            if (!vis[i]) {
                vis[i] = true;
                if (f[i] == i) continue;
                dfs(i);ans--;
                //cout << endl;
            }
        printf("%d\n",ans);
    }
	return 0;
}


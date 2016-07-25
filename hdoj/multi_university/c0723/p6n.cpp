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
int a[10][10];
bool vis[10];
int dfs(int k) {

}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(a,0,sizeof(a));
        memset(vis,false,sizeof(vis));
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&from,to);
            a[from][to] = 1;a[from][0]++;
            a[to][from] = 1;a[to][0]++;
        }
        bool ans = true;
        for (int i = 1;i <= n; i++) {
            if (a[i][0]%2) {
                ans = false;
                break;
            }
        }
        if (ans) {
            for (int i = 1;i <= n; i++) {
                if (!vis[i]) dfs(i);
            }
        } else {
            printf("0\n");
        }
    }
	return 0;
}

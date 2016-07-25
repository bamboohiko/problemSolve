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
const int MAXN = 100 + 10;
bool vis[MAXN];
int main()
{
    int t,n,k;
    scanf("%d",&t);
    while (t--) {
        memset(vis,false,sizeof(vis));
        scanf("%d%d",&n,&k);
        int x;
        bool ans = true;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&x);
            for (;x <= n;x += k) {
                if (!vis[x]) {
                    vis[x] = true;
                    break;
                }
            }
            if (x > n) ans = false;
        }
        if (ans) printf("Jerry\n");
        else printf("Tom\n");
    }
	return 0;
}

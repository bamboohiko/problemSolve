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
const int maxn = 1e5;
bool vis[101000];
int a[101000];
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        memset(vis,0,sizeof(vis));
        for (int i = 1;i <= n; i++) {
            scanf("%d",&k);
            a[k] = 1;
        }
        for (int i = 2;i <= maxn; i++)
            if (!vis[i]){
                for (int j = i << 1; j <= maxn; j += i) {

                }
            }
        printf("%d\n",ans);
    }
	return 0;
}

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
const int add[4][2] = {0,1,0,-1,1,0,-1,0};
int a[60][60];
int main() {
    int t,n,m;
    scanf("%d",&t);
    while (t--) {
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        int ans = 0;
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++) {
                scanf("%d",&a[i][j]);
                if (a[i][j]) ans++;
            }
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++)
                for (int k = 0;k < 4; k++) {
                    ans += max(a[i][j]-a[i+add[k][0]][j+add[k][1]],0);
                }
        printf("%d\n",ans);
    }
	return 0;
}


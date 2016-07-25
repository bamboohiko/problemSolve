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
const int maxn = 1010;
int a[maxn][maxn],r[maxn],ra[maxn],c[maxn],ca[maxn];
int main() {
    int t,n,m,q;
    scanf("%d",&t);
    while (t--) {
        memset(ra,0,sizeof(ra));
        memset(ca,0,sizeof(ca));
        scanf("%d%d%d",&n,&m,&q);
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++)
                scanf("%d",&a[i][j]);
        for (int i = 1;i <= n; i++) r[i] = i;
        for (int j = 1;j <= m; j++) c[j] = j;
        int opt,x,y;
        while (q--) {
            scanf("%d%d%d",&opt,&x,&y);
            if (opt == 1) {swap(r[x],r[y]);swap(ra[x],ra[y]);}
            if (opt == 2) {swap(c[x],c[y]);swap(ca[x],ca[y]);}
            if (opt == 3) ra[x] += y;
            if (opt == 4) ca[x] += y;
        }
        for (int i = 1;i <= n; i++) {
            for (int j = 1;j < m; j++)
                printf("%d ",a[r[i]][c[j]] + ra[i] + ca[j]);
            printf("%d\n",a[r[i]][c[m]] + ra[i] + ca[m]);
        }
    }
	return 0;
}


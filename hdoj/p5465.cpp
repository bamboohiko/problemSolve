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
const int maxn = 500 + 10;
int n,m;
int a[maxn][maxn],b[maxn][maxn];
int lowbit(int k) {
    return k&(-k);
}
void modify(int x,int y,int k) {
    for (int i = x;i <= n;i += lowbit(i))
        for (int j = y;j <= m; j+= lowbit(j)) {
            b[i][j] ^= k;
        }
}
int sum(int x,int y) {
    int sum = 0;
    for (int i = x;i > 0;i -= lowbit(i))
        for (int j = y;j >0;j -= lowbit(j)) {
            sum ^= b[i][j];
        }
    return sum;
}
int main() {
    int t,q;
    scanf("%d",&t);
    while (t--) {
        memset(b,0,sizeof(b));
        scanf("%d%d%d",&n,&m,&q);
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++) {
                scanf("%lld",&a[i][j]);
                modify(i,j,a[i][j]);
            }
        int opt,x1,y1,x2,y2;
        for (int i = 1;i <= q; i++) {
            scanf("%d",&opt);
            if (opt == 1) {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                if (sum(x2,y2)^sum(x1-1,y2)^sum(x2,y1-1)^sum(x1-1,y1-1)) printf("Yes\n");
                else printf("No\n");
            } else {
                scanf("%d%d%d",&x1,&y1,&x2);
                modify(x1,y1,x2^a[x1][y1]);
                a[x1][y1] = x2;
            }
        }
    }
	return 0;
}

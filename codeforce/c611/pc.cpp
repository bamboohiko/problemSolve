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
char a[510][510];
int n,m;
int sum[510][510],decx[510][510],decy[510][510];
int main() {
    scanf("%d%d%*c",&n,&m);
    for (int i = 1;i <= n; i++) {
        for (int j = 1;j <= m; j++)
            scanf("%c",&a[i][j]);
        getchar();
    }
    for (int i = 1;i <= n; i++) {
        for (int j = 1;j <= m; j++) {
            decx[i][j] = decx[i-1][j];decy[i][j] = decy[i][j-1];
            if (a[i][j] == '.' && a[i][j+1] == '.') decx[i][j]++;
            if (a[i][j] == '.' && a[i+1][j] == '.') decy[i][j]++;
            int k = 0;
            if (a[i][j] == '.') {
                if (j < m && a[i][j+1] == '.') k++;
                if (i < n && a[i+1][j] == '.') k++;
             }
             //cout << k << " ";
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + k;
        }
        //cout << endl;
    }
    int q,x1,x2,y1,y2;
    scanf("%d",&q);
    for (int i = 1;i <= q; i++) {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int ans = sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
        ans -= decx[x2][y2] - decx[x1-1][y2] + decy[x2][y2] - decy[x2][y1-1];
        printf("%d\n",ans);
    }
	return 0;
}

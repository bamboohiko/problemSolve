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
int a[5010],f[1010][5010];
int dis(int x) {
    return x*x;
}
int main() {
    int m,n,t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&m,&n);m += 8;
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        memset(f,INF,sizeof(f));
        for (int i = 0;i <= n; i++) f[0][i] = 0;
        for (int i = 1;i <= m; i++) {
            for (int j = n-i*3+1;j > 0; j--) {
                f[i][j] = min(f[i][j+1],f[i-1][j+2] + dis(a[j]-a[j+1]));
                //cout << f[i][j] << " ";
            }
            //cout << endl;
        }
        printf("%d\n",f[m][1]);
    }
	return 0;
}


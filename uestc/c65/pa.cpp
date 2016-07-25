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
const int inf = 1e9 + 7;
int a[110],sum[110],f[110][110];
int query(int l,int r) {
    return (sum[r] - sum[l-1] + 100)%100;
}
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        memset(sum,0,sizeof(sum));
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            sum[i] = (sum[i-1] + a[i])%100;
            f[i][i] = 0;
        }
        for (int len = 1;len < n; len++)
            for (int i = 1;i + len <= n; i++) {
                int j = i + len;
                f[i][j] = inf;
                for (int k = i;k < j; k++)
                    f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+query(i,k)*query(k+1,j));
            }
        printf("%d\n",f[1][n]);
    }
	return 0;
}

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
int f[110][110],a[110],s[110];
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        int n;
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            s[i] = s[i-1] + a[i];
        }
        for (int len = 1;len < n; len++)
            for (int i = 1;i + len <= n; i++) {
                int j = i + len;
                f[i][j] = a[j]*len + f[i][j-1];
                for (int k = i;k <= j; k++)
                    f[i][j] = min(f[i][j],f[i+1][k]+f[k+1][j]+(s[j]-s[k])*(k-i+1)+a[i]*(k-i));
                //printf("%d %d %d\n",i,j,f[i][j]);
            }
        printf("Case #%d: %d\n",ca,f[1][n]);
    }
	return 0;
}


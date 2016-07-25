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
double beat[130][130],f[130][10010],sav[10010];
int a[10010];
int main() {
    int n,m;
    while (scanf("%d",&m) != EOF) {
        memset(f,0,sizeof(f));
        memset(sav,0,sizeof(sav));
        m = m*(m-1)*(m-2)/3/2;
        for (int i = 0;i < m; i++) {
            for (int j = 0;j < m; j++) scanf("%lf",&beat[i][j]);
            beat[i][m] = 1;
            f[i][0] = 1;
        }
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);a[n+1] = m;
        for (int i = 0;i < m; i++) sav[0] = max(sav[0],beat[i][a[1]]);
        for (int j = 1;j <= n; j++)
            for (int i = 0;i < m; i++) {
                f[i][j] = f[i][j-1]*beat[i][a[j]];
                if (i == a[j]) f[i][j] = max(f[i][j],sav[j-1]);
                sav[j] = max(sav[j],f[i][j]*beat[i][a[j+1]]);
                //cout << f[i][j] << endl;
            }
        printf("%.6lf\n",sav[n]);
    }
	return 0;
}


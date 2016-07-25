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
int v[10100];
double f[10100],p[10100];
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        if (n == 0 && m == 0) break;
        for (int i = 0;i <= n; i++) f[i] = 1;
        for (int i = 1;i <= m; i++)
            scanf("%d%lf",&v[i],&p[i]);
        for (int i = 1;i <= m; i++)
            for (int j = n;j >= v[i]; j--)
                f[j] = min(f[j],f[j-v[i]]*(1-p[i]));
        printf("%.1lf%%\n",(1-f[n])*100);
    }
 	return 0;
}

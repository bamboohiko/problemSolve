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
const int n = 1e5 + 10;
int f[n],loc[n];
int main() {
    int n,m,k,ans = 0;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&k);
        if (!f[k]) f[k] = i;
        else f[k] = -1;
    }
    for (int i = 1;i <= m; i++) {
        scanf("%d",&k);
        if (f[k] > 0) loc[i] = f[k];
        else if (ans != 2 && f[k] == -1) ans = 1;
        else ans = 2;
    }
    if (ans == 0) {
        puts("Possible");
        for (int i = 1;i < m; i++) printf("%d ",loc[i]);printf("%d\n",loc[m]);
    } else if (ans == 1) {
        puts("Ambiguity");
    } else {
        puts("Impossible");
    }
	return 0;
}

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
int f[10100],v[510],p[510];
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int v2,v1,n;
        scanf("%d%d",&v1,&v2);
        v2 -= v1;
        scanf("%d",&n);
        memset(f,INF,sizeof(f));f[0] = 0;
        for (int i = 1;i <= n; i++) {
            scanf("%d%d",&p[i],&v[i]);
            for (int j = v[i];j <= v2; j++)
                f[j] = min(f[j],f[j-v[i]] + p[i]);
        }
        if (f[v2] != INF) printf("The minimum amount of money in the piggy-bank is %d.\n",f[v2]);
        else printf("This is impossible.\n");
    }
	return 0;
}

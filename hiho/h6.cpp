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
int v[510],p[510];
int f[100100];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) scanf("%d%d",&v[i],&p[i]);
    for (int i = 1;i <= n; i++)
        for (int j = m;j >= v[i]; j--)
            f[j] = max(f[j],f[j-v[i]]+p[i]);
    printf("%d\n",f[m]);
	return 0;
}

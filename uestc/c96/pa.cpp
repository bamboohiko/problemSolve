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
int t[5010],v[5010],f[5010];
int main() {
    int n,m;
    scanf("%d%d",&m,&n);
    for (int i = 1;i <= n; i++) scanf("%d%d",&t[i],&v[i]);
    for (int i = 1;i <= n; i++)
        for (int j = m;j >= t[i]; j--)
            f[j] = max(f[j],f[j-t[i]]+v[i]);
    printf("%d\n",f[m]);
	return 0;
}

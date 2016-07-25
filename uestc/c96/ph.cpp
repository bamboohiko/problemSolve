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
map<int,int> dir;
int f[1000100];
int main() {
    int n,m,k;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&k);
        dir[k] = i;
    }
    int ans = 0;
    memset(f,INF,sizeof(f));
    for (int j = 1;j <= m; j++) {
        scanf("%d",&k);
        if (dir.count(k)) k = dir[k];
        else continue;
        int loc = lower_bound(f,f+m,k) - f;
        f[loc] = k;
        ans = max(ans,loc);
    }
    if (f[0] < INF) ans++;
    printf("%d\n",ans+1);
	return 0;
}

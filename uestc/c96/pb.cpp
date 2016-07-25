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
const int maxn = 5e5 + 100;
int f[maxn][2],s[maxn];
int main() {
    int n,k,ans = -101;
    scanf("%d",&n);
    memset(f,-INF,sizeof(f));
    memset(s,-INF,sizeof(s));
    f[0][0] = 0;
    for (int i = 1;i <= n; i++) {
        scanf("%d",&k);
        f[i][0] = max(f[i-1][0],0) + k;
        if (i > 2) {
        	s[i-2] = max(s[i-3],f[i-2][0]);
        	f[i][1] = max(f[i-1][1],s[i-2]) + k;
        	ans = max(ans,f[i][1]);
        }
    }
    //for (int i = 1;i <= n; i++)
    //    printf("%d %d %d\n",f[i][0], f[i][1],s[i]);
    printf("%d\n",ans);
	return 0;
}

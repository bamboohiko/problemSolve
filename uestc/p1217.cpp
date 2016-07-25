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
const LL mod = 1e9 + 7;
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= i && j <= m; j++) {
                f[i][j] = (f[i][j] + query(i,j-1))%mod;
                updata(i,j,f[i][j]);
            }

    }
	return 0;
}

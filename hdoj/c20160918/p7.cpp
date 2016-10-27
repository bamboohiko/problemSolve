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
typedef unsigned long long LL;
LL f[30][30][10];
void init() {
    for (int k = 0;k < 10; k++) f[1][1][k] = 1;
    for (int i = 1;i < 20; i++)
        for (int j = 1;j <= i; j++)
            for (int k = 0;k < 10; k++) {
                for (int k2 = 0;k2 < 10; k2++) {
                    if ((k+k2)%2 == 1 && (j+k)%2 == 1) f[i+1][1][k2] += f[i][j][k];
                    if ((k+k2)%2 == 0) f[i+1][j+1][k2] += f[i][j][k];
                }
            }
}
LL sum(LL d) {
    LL ans = 0;
    for (int i = 1;d > 0;i++) {
        int loc = d%10;
        if (loc == 0) loc = 10;
        for (int j = 1;j <= i; j++) {
            if (d > 10) ans += f[i][j][0];
            for (int k = 1;k < loc; k++)
                if ((j+k)%2 == 1) ans += f[i][j][k];
        }
        d /= 10;
    }
    return ans;
}
int main() {
    init();
    int t,ca = 0;
    scanf("%d",&t);
    LL l,r;
    while (t--) {
        scanf("%I64d%I64d",&l,&r);
        printf("Case #%d: %I64d\n",++ca,sum(r)-sum(l-1));
    }
	return 0;
}

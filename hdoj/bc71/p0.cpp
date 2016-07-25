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
const LL maxn = 1e18;
LL f[1010],s[1010];
int main() {
    f[1] = 1;f[2] = 2;
    s[1] = 1;s[2] = 3;
    for (int i = 3; ;i++) {
        f[i] = f[i-1] + f[i-2];
        s[i] = s[i-1] + f[i];
        //printf("%lld %lld\n",f[i],s[i]);
        if (s[i] > maxn) break;
    }
    int t;LL n;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld",&n);
        for (int i = 1; ;i++)
            if (s[i] > n) {
                printf("%d\n",i-1);
                break;
            }
    }
	return 0;
}


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
int main() {
    LL l,r;
    while (scanf("%I64d%I64d",&l,&r) != EOF) {
        LL ans = 0;
        if (r <= 1) ans = 0;
        else if (r <= 2) ans = 1;
        else {
            ans = 2;
            if (l == 0) r -= 3;
            else r -= l+2;
            if (r > 0) ans += r/2;
        }
        printf("%I64d\n",ans);
    }
	return 0;
}

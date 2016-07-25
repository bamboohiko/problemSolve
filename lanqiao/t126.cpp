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
    LL n,m;
    scanf("%lld%lld",&n,&m);
    LL ans = (LL)sqrt(n) * (LL)sqrt(m);
    printf("%lld",ans);
	return 0;
}

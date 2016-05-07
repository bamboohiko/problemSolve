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
int n;
LL k,a[100100],b[100100];
bool check(LL s) {
    LL sum = k;
    for (int i = 1;i <= n; i++) {
        if (b[i] < a[i]*s) sum -= a[i]*s-b[i];
        if (sum < 0) return false;
    }
    return true;
}
int main() {
    scanf("%d%I64d",&n,&k);
    for (int i = 1;i <= n; i++) scanf("%I64d",&a[i]);
    for (int i = 1;i <= n; i++) scanf("%I64d",&b[i]);
    LL l = 0,r = 2e9 + 1;
    while (l + 1 < r) {
        int mid = l + ((r-l) >> 1);
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%I64d\n",l);
	return 0;
}


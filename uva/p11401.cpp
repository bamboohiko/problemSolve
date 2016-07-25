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
using namespace std;
typedef long long LL;
const int maxn = 1e6;
LL f[maxn + 10],sum[maxn + 10];
void init() {
    for (LL i = 4;i <= maxn; i++) {
        f[i] = ((i-2)*(i-1)/2 - ((i-1) >> 1))/2;
        sum[i] = sum[i-1] + f[i];
    }
}
int main() {
    init();
    int n;
    while (scanf("%d",&n) != EOF && n >= 3)
        printf("%lld\n",sum[n]);
	return 0;
}


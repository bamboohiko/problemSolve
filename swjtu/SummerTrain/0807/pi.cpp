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
const LL m = 10007;
LL f[20010];
int main() {
    f[0] = 0;f[1] = 1;
    for (int i = 2;i < 10000; i++)
        f[i] = (f[i-1] + 2*f[i-2] + 1)%m;
    int n;
    while (scanf("%d",&n) != EOF)
        printf("%lld\n",f[n]);
	return 0;
}

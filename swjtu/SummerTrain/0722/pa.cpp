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
const int maxn = 50;
long long f[maxn + 10];
int main() {
    f[0] = 1;f[1] = 1;f[2] = 2;
    for (int i = 3;i <= maxn; i++)
        f[i] = f[i-1] + f[i-2] + f[i-3];
    int n;
    while (scanf("%d",&n) != EOF && n) {
        printf("%lld\n",f[n]);
    }
	return 0;
}

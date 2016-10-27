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
int f[30];
void init() {
    int n = 20;
    for (int i = 0,j = 1;j <= n;) {
        int k = i;
        i = j;
        j = k+j;
        f[j]++;
    }
    for (int i = 1;i <= n; i++) f[i] += f[i-1];
}
int main() {
    init();
    int t,n,ca = 0;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        printf("Case #%d: %d\n",++ca,n-f[n]);
    }
	return 0;
}

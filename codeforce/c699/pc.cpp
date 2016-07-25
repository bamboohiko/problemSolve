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
int a[110],f[110][3];
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    for (int i = 1;i <= n+1; i++) {
        if (a[i] == 2 || a[i] == 3) f[i][1] = max(f[i-1][0],f[i-1][2])+1;
        if (a[i] == 1 || a[i] == 3) f[i][2] = max(f[i-1][0],f[i-1][1])+1;
        f[i][0] = max(f[i-1][0],max(f[i-1][1],f[i-1][2]));
    }
    printf("%d\n",n-f[n+1][0]);
	return 0;
}

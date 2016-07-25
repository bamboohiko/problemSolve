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
const int maxn = 30;
LL f[50][2],p[30];
void init() {
    p[0] = 1;
    for (int i = 1;i <= maxn; i++) p[i] = p[i-1] << 1;
    f[0][1] = f[1][1] = f[2][1] = 0;
    f[0][0] = 1;f[1][0] = 2;f[2][0] = 4;
    for (int i = 3;i <= maxn; i++) {
        f[i][1] = p[i-3];
        for (int j = 2;j <= i-2; j++)
            f[i][1] += f[j-2][0]*p[i-(j+2)];
        f[i][0] = p[i] - f[i][1];
    }
}
int main() {
    init();
    int n;
    while (scanf("%d",&n) != EOF && n) {
        cout << f[n][1] << endl;
    }
	return 0;
}

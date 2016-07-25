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
bool vis[110];
int a[110];
int main() {
    int n,sum = 0;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    sum /= n/2;
    for (int i = 1;i <= n; i++)
        for (int j = 1;j <= n; j++)
        if (i != j && !vis[i] && !vis[j] && a[i] + a[j] == sum) {
            printf("%d %d\n",i,j);
            vis[i] = vis[j] = true;
        }
	return 0;
}

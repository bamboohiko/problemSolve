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
int a[110];
int main() {
    int n,m,k;
    int num,loc;
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1;i <= k; i++)
        scanf("%d",&a[i]);
    int ans = 0;
    for (int i = 1;i <= n; i++)
        for (int j = 1;j <= m; j++) {
            scanf("%d",&num);
            for (int i = 1;i <= k; i++)
                if (a[i] == num) {
                    loc = i;
                    break;
                }
            for (int i = loc;i > 1; i--) a[i] = a[i-1];a[1] = num;
            ans += loc;
        }
    printf("%d\n",ans);
	return 0;
}


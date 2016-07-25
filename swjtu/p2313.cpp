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
int a[110];
bool cmp(int a,int b) {
    return abs(a) > abs(b);
}
int main() {
    int n,m,k;
    while (scanf("%d%d%d",&n,&m,&k) != EOF) {
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp);
        for (int i = 1;i <= n; i++)
            if (a[i]*k > 0) {
                a[i] *= k;
                break;
            }
        if (k == 0)
            for (int i = 1;i <= n; i++) if (a[i] < 0) {
                a[i] = 0;
                break;
            }
        sort(a+1,a+n+1);
        int ans = 0;
        for (int i = n;n >= 1 && m--; i--)
                ans += a[i];
        printf("%d\n",ans);
    }
	return 0;
}

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
char st[200100];
int a[200100];
int main() {
    int n;
    scanf("%d%s",&n,st);
    for (int i = 0;i < n; i++) scanf("%d",&a[i]);
    int ans = -1;
    for (int i = 1;i < n; i++)
        if (st[i-1] == 'R' && st[i] == 'L') {
            if (ans == -1) ans = (a[i] - a[i-1])/2;
            else ans = min(ans,(a[i] - a[i-1])/2);
        }
    printf("%d\n",ans);
	return 0;
}

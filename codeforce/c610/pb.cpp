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
typedef long long LL;
using namespace std;
int a[401000];
int main() {
    int n, val = INF;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        a[n+i] = a[i];
        val = min(val,a[i]);
    }
    int ans = 0,len = 0;
    for (int i = 1;i <= n+n; i++) {
        if (a[i] > val) len++;
        else {
            ans = max(ans,len);
            len = 0;
        }
    }
    printf("%I64d\n",(LL)val*n + ans);
	return 0;
}

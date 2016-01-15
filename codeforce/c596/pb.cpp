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
int a[200100];
int main() {
    int n;
    long long ans = 0;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        ans += abs(a[i]-a[i-1]);
    }
    printf("%I64d\n",ans);
	return 0;
}

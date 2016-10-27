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
LL a[100100];
int id[100100];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    LL ans = 0,sum = 0;
    for (int i = 1;i <= n; i++) {
        scanf("%I64d",&a[i]);
        ans += a[i-1]*a[i];
        sum += a[i];
    }
    a[0] = a[n];a[n+1] = a[1];
    ans += a[1]*a[n];
    for (int i = 1;i <= k; i++) scanf("%d",&id[i]);
    sort(id+1,id+k+1);id[0] = n;
    for (int i = 1;i <= k; i++) {
        sum -= a[id[i]];
        if (id[i-1] == id[i]-1) ans += a[id[i]]*(sum - a[id[i]+1]);
        else ans += a[id[i]]*(sum - a[id[i]-1] -a[id[i]+1]);
    }
    if (id[k] == n && id[1] == 1) ans += a[n]*a[1];
    printf("%I64d",ans);
	return 0;
}

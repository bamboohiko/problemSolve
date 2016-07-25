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
int a[1010];
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l = 2,r = n;
    printf("%d",a[1]);
    while (l <= r) {
        printf(" %d",a[r--]);
        if (l <= r) printf(" %d",a[l++]);
    }
    printf("\n");
	return 0;
}

